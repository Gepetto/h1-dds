#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include <unitree/idl/go2/LowState_.hpp>
#include <unitree/idl/go2/SportModeState_.hpp>
#include <unitree/idl/go2/LowCmd_.hpp>
#include "unitree_sdk2_bridge.cpp"

#define TOPIC_LOWSTATE "rt/lowstate"
#define TOPIC_HIGHSTATE "rt/sportmodestate"
#define TOPIC_LOWCMD "rt/lowcmd"

using namespace unitree::robot;
using namespace unitree::common;

void LowStateHandler(const void *msg)
{
    const unitree_go::msg::dds_::LowState_ *s = (const unitree_go::msg::dds_::LowState_ *)msg;

    std::cout << "Quaternion: "
              << s->imu_state().quaternion()[0] << " "
              << s->imu_state().quaternion()[1] << " "
              << s->imu_state().quaternion()[2] << " "
              << s->imu_state().quaternion()[3] << " " << std::endl;
}

void HighStateHandler(const void *msg)
{
    const unitree_go::msg::dds_::SportModeState_ *s = (const unitree_go::msg::dds_::SportModeState_ *)msg;

    std::cout << "Position: "
              << s->position()[0] << " "
              << s->position()[1] << " "
              << s->position()[2] << " " << std::endl;
}

int main()
{
    ChannelFactory::Instance()->Init(1, "lo");
    UnitreeSdk2Bridge unitree_interface;

    unitree_interface.Run();

    // while (true)
    // {
    //     unitree_go::msg::dds_::LowCmd_ low_cmd{};
    //     for (int i = 0; i < 20; i++)
    //     {
    //         low_cmd.motor_cmd()[i].q() = 0;
    //         low_cmd.motor_cmd()[i].kp() = 0;
    //         low_cmd.motor_cmd()[i].dq() = 0;
    //         low_cmd.motor_cmd()[i].kd() = 0;
    //         low_cmd.motor_cmd()[i].tau() = 1;
    //     }
    //     low_cmd_puber.Write(low_cmd);
    //     usleep(2000);
    // }

    return 0;
}
