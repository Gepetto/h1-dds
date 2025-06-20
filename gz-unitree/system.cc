#include "include/system.hpp"
#include <gz/plugin/Register.hh>
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
}

UnitreePlugin::~UnitreePlugin()
{
}

void UnitreePlugin::CmdHandler(const void *msg)
{
    gzmsg << "UnitreePlugin::CmdHandler" << std::endl;
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

void UnitreePlugin::PostUpdate(const gz::sim::UpdateInfo &_info,
                               const gz::sim::EntityComponentManager &_ecm)
{
    gzmsg << "UnitreePlugin::PostUpdate" << std::endl;
}

void UnitreePlugin::PreUpdate(const gz::sim::UpdateInfo &_info,
                              gz::sim::EntityComponentManager &_ecm)
{
    gzmsg << "UnitreePlugin::PreUpdate" << std::endl;
}

void UnitreePlugin::Configure(const gz::sim::Entity &_entity,
                              const std::shared_ptr<const sdf::Element> &_sdf,
                              gz::sim::EntityComponentManager &_ecm,
                              gz::sim::EventManager &_eventMgr)
{
    ChannelFactory::Instance()->Init(1, "lo");

    ChannelPublisherPtr<unitree_hg::msg::dds_::LowState_> publisher = ChannelPublisherPtr<unitree_hg::msg::dds_::LowState_>(new ChannelPublisher<unitree_hg::msg::dds_::LowState_>("rt/lowstate"));
    publisher->InitChannel();

    ChannelSubscriberPtr<unitree_hg::msg::dds_::LowCmd_> subscriber = ChannelSubscriberPtr<unitree_hg::msg::dds_::LowCmd_>(new ChannelSubscriber<unitree_hg::msg::dds_::LowCmd_>("rt/lowcmd"));
    subscriber->InitChannel(
        std::bind(&UnitreePlugin::CmdHandler, this, std::placeholders::_1), 1);
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
