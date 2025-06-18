#include <gz/sim/System.hh>

namespace gz_unitree
{
    class UnitreePlugin :
        // This class is a system.
        public gz::sim::System,
        public gz::sim::ISystemPostUpdate,
        public gz::sim::ISystemPreUpdate
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
    };
}
