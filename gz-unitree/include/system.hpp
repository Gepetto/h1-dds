#include <gz/sim/System.hh>

namespace gz_unitree
{
    class UnitreePlugin :
        // This class is a system.
        public gz::sim::System,
        public gz::sim::ISystemPostUpdate,
        public gz::sim::ISystemPreUpdate,
        public gz::sim::ISystemConfigure
    {
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
