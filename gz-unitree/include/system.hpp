#include <gz/sim/System.hh>
#include "../data.hpp"
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/idl/hg/LowCmd_.hpp>
#include <unitree/idl/hg/LowState_.hpp>

using namespace unitree::common;
using namespace unitree::robot;

namespace gz_unitree
{
    class UnitreePlugin :
        // This class is a system.
        public gz::sim::System,
        public gz::sim::ISystemPostUpdate,
        public gz::sim::ISystemPreUpdate,
        public gz::sim::ISystemConfigure
    {
    private:
        // This is a private method that will be used to handle commands.
        void CmdHandler(const void *msg);

    private:
        // Buffers
        DataBuffer<MotorState> motor_state_buffer;
        DataBuffer<MotorCommand> motor_command_buffer;
        DataBuffer<ImuState> imu_state_buffer;

    public:
        UnitreePlugin();

    public:
        ~UnitreePlugin() override;

    public:
        void PreUpdate(const gz::sim::UpdateInfo &_info,
                       gz::sim::EntityComponentManager &_ecm) override;

    public:
        void PostUpdate(const gz::sim::UpdateInfo &_info,
                        const gz::sim::EntityComponentManager &_ecm) override;

    public:
        void Configure(const gz::sim::Entity &_id,
                       const std::shared_ptr<const sdf::Element> &_sdf,
                       gz::sim::EntityComponentManager &_ecm,
                       gz::sim::EventManager &_eventMgr) override;
    };
}
