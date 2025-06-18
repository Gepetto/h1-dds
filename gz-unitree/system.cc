#include "./system.hpp"
#include <gz/plugin/Register.hh>

using namespace gz_unitree;

UnitreePlugin::UnitreePlugin()
{
}

UnitreePlugin::~UnitreePlugin()
{
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

// Include a line in your source file for each interface implemented.
GZ_ADD_PLUGIN(
    UnitreePlugin,
    gz::sim::System,
    UnitreePlugin::ISystemPostUpdate,
    UnitreePlugin::ISystemPreUpdate)
