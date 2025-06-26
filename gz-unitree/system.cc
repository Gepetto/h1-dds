#include "include/system.hpp"
#include <gz/plugin/Register.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/Joint.hh>
#include <gz/sim/Sensor.hh>
// FIXME runtime linker error
// #include <gz/sensors/ForceTorqueSensor.hh>
#include <gz/math/Pose3.hh>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include "crc32.cc"
#include "data.hpp"

#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/idl/hg/LowCmd_.hpp>
#include <unitree/idl/hg/LowState_.hpp>

#define header "[Unitree] "

using namespace gz_unitree;
using namespace unitree::common;
using namespace unitree::robot;

float GetMotorKp(MotorType type)
{
    switch (type)
    {
    case GearboxS:
        return 80;
    case GearboxM:
        return 100;
    case GearboxL:
        return 200;
    default:
        return 0;
    }
}

float GetMotorKd(MotorType type)
{
    switch (type)
    {
    case GearboxS:
        return 2;
    case GearboxM:
        return 3;
    case GearboxL:
        return 5;
    default:
        return 0;
    }
}

UnitreePlugin::UnitreePlugin()
{
    this->state_sent = false;
    this->joints_logged = false;
}

UnitreePlugin::~UnitreePlugin()
{
}

void UnitreePlugin::CmdHandler(const void *msg)
{
    gzmsg << header << "got a cmd message" << std::endl;
    unitree_hg::msg::dds_::LowCmd_ _cmd = *(const unitree_hg::msg::dds_::LowCmd_ *)msg;

    MotorCommand motor_command_tmp;
    for (size_t i = 0; i < H1_NUM_MOTOR; ++i)
    {
        motor_command_tmp.tau_ff[i] = _cmd.motor_cmd()[i].tau();
        motor_command_tmp.q_target[i] = _cmd.motor_cmd()[i].q();
        motor_command_tmp.dq_target[i] = _cmd.motor_cmd()[i].dq();
        motor_command_tmp.kp[i] = _cmd.motor_cmd()[i].kp();
        motor_command_tmp.kd[i] = _cmd.motor_cmd()[i].kd();
    }

    this->motor_command_buffer.SetData(motor_command_tmp);
}

void UnitreePlugin::LowStateWriter()
{
}

void UnitreePlugin::PostUpdate(const gz::sim::UpdateInfo &_info,
                               const gz::sim::EntityComponentManager &ecm)
{
}

void UnitreePlugin::PreUpdate(const gz::sim::UpdateInfo &_info,
                              gz::sim::EntityComponentManager &ecm)
{
    unitree_hg::msg::dds_::LowState_ lowstate{};
    gz::sim::Model model = gz::sim::Model(this->model_id);

    uint motor_state_index = 0;
    for (std::string joint_name : H1_2JointNames)
    {
        gz::sim::Joint joint = gz::sim::Joint(model.JointByName(ecm, joint_name));
        gz::math::v7::Pose3d pose = joint.Pose(ecm).value();
        auto velocity = joint.Velocity(ecm);

        // auto generic_sensor = gz::sim::Sensor(joint.SensorByName(ecm, "torque"));
        // auto sensor = gz::sensors::ForceTorqueSensor();

        // gzmsg << header << "on " << joint_name
        //       << ": torque = " << sensor.Force()
        //       << std::endl;

        // Velocity has only one component????
        // if (velocity.has_value())
        // {
        //     uint i = 0;
        //     for (auto component : velocity.value())
        //     {
        //         gzmsg << header << "on " << joint_name
        //               << ": velocity[" << i << "] = " << component
        //               << std::endl;
        //         i++;
        //     }
        // }

        float angle;
        if (joint_name.find("pitch_joint") != std::string::npos)
        {
            angle = pose.Pitch();
        }
        if (joint_name.find("roll_joint") != std::string::npos)
        {
            angle = pose.Roll();
        }
        if (joint_name.find("yaw_joint") != std::string::npos || joint_name == "torso_joint")
        {
            angle = pose.Yaw();
        }
        if (joint_name == "left_elbow_joint" || joint_name == "right_elbow_joint")
        {
            angle = pose.Roll();
        }

        lowstate.motor_state().at(motor_state_index).q() = angle;

        motor_state_index++;
    }

    lowstate.crc() = crc32_core((uint32_t *)&lowstate, (sizeof(unitree_hg::msg::dds_::LowState_) >> 2) - 1);
    this->state_publisher->Write(lowstate);
}

void UnitreePlugin::Configure(const gz::sim::Entity &id,
                              const std::shared_ptr<const sdf::Element> &_sdf,
                              gz::sim::EntityComponentManager &ecm,
                              gz::sim::EventManager &_eventMgr)
{
    this->model_id = id;
    ChannelFactory::Instance()->Init(1, "lo");
    // this->ecm = *&ecm;

    gzmsg << header << "Created instance on DDS domain 1 with network interface 'lo'" << std::endl;

    this->state_publisher = ChannelPublisherPtr<unitree_hg::msg::dds_::LowState_>(new ChannelPublisher<unitree_hg::msg::dds_::LowState_>("rt/lowstate"));
    this->state_publisher->InitChannel();

    this->publisher_thread =
        CreateRecurrentThreadEx("low_state_writer", UT_CPU_ID_NONE, 2000,
                                &UnitreePlugin::LowStateWriter, this);

    gzmsg << header << "Created publisher on channel 'rt/lowstate'" << std::endl;

    ChannelSubscriberPtr<unitree_hg::msg::dds_::LowCmd_> subscriber = ChannelSubscriberPtr<unitree_hg::msg::dds_::LowCmd_>(new ChannelSubscriber<unitree_hg::msg::dds_::LowCmd_>("rt/lowcmd"));
    subscriber->InitChannel(
        std::bind(&UnitreePlugin::CmdHandler, this, std::placeholders::_1), 1);

    gzmsg << header << "Created subscriber on channel 'rt/lowcmd'" << std::endl;

    gz::sim::Model model = gz::sim::Model(this->model_id);

    for (std::string joint_name : H1_2JointNames)
    {
        gz::sim::Joint joint = gz::sim::Joint(model.JointByName(ecm, joint_name));
        joint.EnableVelocityCheck(ecm);
    }

    gzmsg << header << "Enabled velocity checking for all of model's joints" << std::endl;

    this->joints_logged = true;
}

// Include a line in your source file for each interface implemented.
GZ_ADD_PLUGIN(
    UnitreePlugin,
    gz::sim::System,
    UnitreePlugin::ISystemPostUpdate,
    UnitreePlugin::ISystemPreUpdate,
    UnitreePlugin::ISystemConfigure)

GZ_ADD_PLUGIN_ALIAS(
    UnitreePlugin,
    "gz::sim::systems::UnitreePlugin")
