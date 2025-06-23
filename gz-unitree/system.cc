#include "include/system.hpp"
#include <gz/plugin/Register.hh>
#include <gz/sim/Model.hh>
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

    while (true)
    {

        unitree_hg::msg::dds_::LowState_ lowstate{};
        lowstate.crc() = crc32_core((uint32_t *)&lowstate, (sizeof(unitree_hg::msg::dds_::LowState_) >> 2) - 1);
        this->state_publisher->Write(lowstate);
        usleep(2000);
    }
}

void UnitreePlugin::PostUpdate(const gz::sim::UpdateInfo &_info,
                               const gz::sim::EntityComponentManager &ecm)
{
}

void UnitreePlugin::PreUpdate(const gz::sim::UpdateInfo &_info,
                              gz::sim::EntityComponentManager &_ecm)
{
}

void UnitreePlugin::Configure(const gz::sim::Entity &id,
                              const std::shared_ptr<const sdf::Element> &_sdf,
                              gz::sim::EntityComponentManager &ecm,
                              gz::sim::EventManager &_eventMgr)
{
    ChannelFactory::Instance()->Init(1, "lo");

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

    this->joints_logged = true;
    gz::sim::Model model = gz::sim::Model(id);
    gzmsg << header << "Joint: " << model.JointByName(ecm, "left_hip_yaw_joint") << std::endl;
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
