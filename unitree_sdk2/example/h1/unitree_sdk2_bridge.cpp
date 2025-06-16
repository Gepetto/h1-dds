#include "unitree_sdk2_bridge.h"

UnitreeSdk2Bridge::UnitreeSdk2Bridge()
{

    // if (idl_type_ == 0)
    // {
    //     low_cmd_go_suber_.reset(new ChannelSubscriber<unitree_go::msg::dds_::LowCmd_>(TOPIC_LOWCMD));
    //     low_cmd_go_suber_->InitChannel(bind(&UnitreeSdk2Bridge::LowCmdGoHandler, this, placeholders::_1), 1);

    //     low_state_go_puber_.reset(new ChannelPublisher<unitree_go::msg::dds_::LowState_>(TOPIC_LOWSTATE));
    //     low_state_go_puber_->InitChannel();

    //     lowStatePuberThreadPtr = CreateRecurrentThreadEx("lowstate", UT_CPU_ID_NONE, 2000, &UnitreeSdk2Bridge::PublishLowStateGo, this);
    // }
    // else
    // {
        low_cmd_hg_suber_.reset(new ChannelSubscriber<unitree_hg::msg::dds_::LowCmd_>(TOPIC_LOWCMD));
        low_cmd_hg_suber_->InitChannel(bind(&UnitreeSdk2Bridge::LowCmdHgHandler, this, placeholders::_1), 1);

        std::cout << "unitree sdk2 brdige low cmd subber initialized." << std::endl;


        low_state_hg_puber_.reset(new ChannelPublisher<unitree_hg::msg::dds_::LowState_>(TOPIC_LOWSTATE));
        low_state_hg_puber_->InitChannel();

        std::cout << "unitree sdk2 brdige low state puber initialized." << std::endl;

        lowStatePuberThreadPtr = CreateRecurrentThreadEx("lowstate", UT_CPU_ID_NONE, 2000, &UnitreeSdk2Bridge::PublishLowStateHg, this);
    // }

    high_state_puber_.reset(new ChannelPublisher<unitree_go::msg::dds_::SportModeState_>(TOPIC_HIGHSTATE));
    high_state_puber_->InitChannel();
    wireless_controller_puber_.reset(new ChannelPublisher<unitree_go::msg::dds_::WirelessController_>(TOPIC_WIRELESS_CONTROLLER));
    wireless_controller_puber_->InitChannel();

    HighStatePuberThreadPtr = CreateRecurrentThreadEx("highstate", UT_CPU_ID_NONE, 2000, &UnitreeSdk2Bridge::PublishHighState, this);
    WirelessControllerPuberThreadPtr = CreateRecurrentThreadEx("wirelesscontroller", UT_CPU_ID_NONE, 2000, &UnitreeSdk2Bridge::PublishWirelessController, this);
}

UnitreeSdk2Bridge::~UnitreeSdk2Bridge()
{
}

void UnitreeSdk2Bridge::LowCmdGoHandler(const void *msg)
{
}

void UnitreeSdk2Bridge::LowCmdHgHandler(const void *msg)
{
    std::cout << "LowCmdHgHandler called." << std::endl;
}

void UnitreeSdk2Bridge::PublishLowStateGo()
{
}

void UnitreeSdk2Bridge::PublishLowStateHg()
{
}

void UnitreeSdk2Bridge::PublishHighState()
{
}

void UnitreeSdk2Bridge::PublishWirelessController()
{
}

void UnitreeSdk2Bridge::Run()
{
    while (1)
    {
        sleep(2);
    }
}

void UnitreeSdk2Bridge::SetupJoystick(string device, string js_type, int bits)
{
}
