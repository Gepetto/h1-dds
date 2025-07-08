#include "include/system.hpp"
#include <gz/plugin/Register.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/Joint.hh>
#include <gz/sim/Sensor.hh>
#include <gz/math/Pose3.hh>
#include <gz/transport.hh>
#include <gz/msgs/Utility.hh>
#include <gz/msgs/imu.pb.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include "crc32.cc"
#include "data.hpp"
#include "data.cpp"

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
    // this->imu_subscriber = gz::transport::Node();
}

UnitreePlugin::~UnitreePlugin()
{
}

void UnitreePlugin::CmdHandler(const void *msg)
{
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

void UnitreePlugin::IMUHandler(const gz::msgs::IMU &_msg)
{
    /*

    header {
  stamp {
    sec: 2
  }
  data {
    key: "frame_id"
    value: "h1_2::torso_link::imu_sensor"
  }
  data {
    key: "seq"
    value: "2"
  }
}
entity_name: "h1_2::torso_link::imu_sensor"
orientation {
  x: 0.038351578720791125
  y: 0.705539905060143
  z: -0.038790669484018513
  w: 0.70656767739426707
}
angular_velocity {
  x: -0.17287533017185
  y: -0.13795466768844261
  z: -0.091267442211552072
}
linear_acceleration {
  x: -9.800593283287748
  y: 0.45835671778499282
  z: -0.2208827579913305
}



====

dds message:

quaternion[4] 	Quaternion of body posture, order: w、x、y、z
rpy[3] 	Body attitude Euler angle information, order: r、p、y
gyroscope[3] 	Aircraft attitude three-axis angular velocity information, order: r、p、y
accelerometer[3] 	Three-axis acceleration information of the aircraft body, order: x、y、z

    */
    gzmsg << header << "Received IMU data" << std::endl;
    this->imu_state_buffer.Clear();

    double w = _msg.orientation().w();
    double x = _msg.orientation().x();
    double y = _msg.orientation().y();
    double z = _msg.orientation().z();

    ImuState imu_state_tmp;

    imu_state_tmp.quaternion[0] = w;
    imu_state_tmp.quaternion[1] = x;
    imu_state_tmp.quaternion[2] = y;
    imu_state_tmp.quaternion[3] = z;

    imu_state_tmp.accelerometer[0] = _msg.linear_acceleration().x();
    imu_state_tmp.accelerometer[1] = _msg.linear_acceleration().y();
    imu_state_tmp.accelerometer[2] = _msg.linear_acceleration().z();

    imu_state_tmp.rpy[0] = atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y));
    imu_state_tmp.rpy[1] = asin(2 * (w * y - z * x));
    imu_state_tmp.rpy[2] = atan2(2 * (w * z + x * y), 1 - 2 * (y * y + z * z));

    // why is angular velocity in x/y/z ???
    // auto gyro = BodyAngularVelocityToEulerRates(
    //     _msg.angular_velocity().x(),
    //     _msg.angular_velocity().y(),
    //     _msg.angular_velocity().z(),
    //     imu_state_tmp.rpy[0],
    //     imu_state_tmp.rpy[1]);

    imu_state_tmp.gyroscope[0] = _msg.angular_velocity().x();
    imu_state_tmp.gyroscope[1] = _msg.angular_velocity().y();
    imu_state_tmp.gyroscope[2] = _msg.angular_velocity().z();

    this->imu_state_buffer.SetData(imu_state_tmp);
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
        auto position = joint.Position(ecm).value();
        auto velocity = joint.Velocity(ecm);

        float angle = 0.0f;
        if (position.size() > 0)
        {
            angle = position.at(0);
        }
        else
        {
            continue;
        }

        lowstate.motor_state().at(motor_state_index).q() = angle;

        if (velocity.has_value() && velocity.value().size() == 1)
        {
            lowstate.motor_state().at(motor_state_index).dq() = velocity.value().at(0);
        }
        else
        {
            lowstate.motor_state().at(motor_state_index).dq() = 0.0f;
        }

        motor_state_index++;
    }

    auto imu = this->imu_state_buffer.GetData();

    if (imu)
    {
        lowstate.imu_state().quaternion().at(0) = imu->quaternion[0];
        lowstate.imu_state().quaternion().at(1) = imu->quaternion[1];
        lowstate.imu_state().quaternion().at(2) = imu->quaternion[2];
        lowstate.imu_state().quaternion().at(3) = imu->quaternion[3];
        lowstate.imu_state().gyroscope().at(0) = imu->gyroscope[0];
        lowstate.imu_state().gyroscope().at(1) = imu->gyroscope[1];
        lowstate.imu_state().gyroscope().at(2) = imu->gyroscope[2];
        lowstate.imu_state().accelerometer().at(0) = imu->accelerometer[0];
        lowstate.imu_state().accelerometer().at(1) = imu->accelerometer[1];
        lowstate.imu_state().accelerometer().at(2) = imu->accelerometer[2];
        lowstate.imu_state().rpy().at(0) = imu->rpy[0];
        lowstate.imu_state().rpy().at(1) = imu->rpy[1];
        lowstate.imu_state().rpy().at(2) = imu->rpy[2];
        lowstate.imu_state().temperature() = imu->temperature;
    }

    lowstate.crc() = crc32_core((uint32_t *)&lowstate, (sizeof(unitree_hg::msg::dds_::LowState_) >> 2) - 1);
    this->state_publisher->Write(lowstate);

    auto cmdbuf = this->motor_command_buffer.GetData();

    motor_state_index = 0;
    for (std::string joint_name : H1_2JointNames)
    {
        gz::sim::Joint joint = gz::sim::Joint(model.JointByName(ecm, joint_name));

        if (!cmdbuf || cmdbuf->q_target.size() <= motor_state_index)
        {
            motor_state_index++;
            continue;
        }

        auto force = cmdbuf->tau_ff.at(motor_state_index) +
                     cmdbuf->kp.at(motor_state_index) * (cmdbuf->q_target.at(motor_state_index) - lowstate.motor_state().at(motor_state_index).q()) +
                     cmdbuf->kd.at(motor_state_index) * (cmdbuf->dq_target.at(motor_state_index) - lowstate.motor_state().at(motor_state_index).dq());

        std::vector<double> torque = {force};
        joint.SetForce(ecm, torque);

        motor_state_index++;
    }
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

    this->cmd_subscriber = ChannelSubscriberPtr<unitree_hg::msg::dds_::LowCmd_>(new ChannelSubscriber<unitree_hg::msg::dds_::LowCmd_>("rt/lowcmd"));
    this->cmd_subscriber->InitChannel(
        std::bind(&UnitreePlugin::CmdHandler, this, std::placeholders::_1), 1);

    gzmsg << header << "Created subscriber on channel 'rt/lowcmd'" << std::endl;

    gz::sim::Model model = gz::sim::Model(this->model_id);

    model.SelfCollide(ecm);

    for (std::string joint_name : H1_2JointNames)
    {
        gz::sim::Joint joint = gz::sim::Joint(model.JointByName(ecm, joint_name));
        joint.EnableVelocityCheck(ecm);
        joint.EnablePositionCheck(ecm);
    }

    gzmsg << header << "Enabled velocity and position checking for all of model's joints" << std::endl;

    std::function<void(const gz::msgs::IMU &)> bound_imu_cb = std::bind(&UnitreePlugin::IMUHandler, this, std::placeholders::_1);
    if (!this->imu_subscriber.Subscribe("/imu", bound_imu_cb))
    {
        gzerr << header << "Failed to subscribe to IMU topic" << std::endl;
        return;
    }
    else
    {
        gzmsg << header << "Subscribed to IMU topic" << std::endl;
    }
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
