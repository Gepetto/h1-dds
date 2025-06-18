#include "./system.hpp"
#include <gz/plugin/Register.hh>
#include <iostream>
#include <fstream>

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

void UnitreePlugin::Configure(const gz::sim::Entity &_entity,
                              const std::shared_ptr<const sdf::Element> &_sdf,
                              gz::sim::EntityComponentManager &_ecm,
                              gz::sim::EventManager &_eventMgr)
{
    std::ofstream myfile;
    myfile.open("/work/feur.txt");
    myfile << "boomboclat";
    myfile.close();
    // This method is called when the system is configured.
    // You can initialize your plugin here.
    gzmsg << "UnitreePlugin::Configure" << std::endl;
}

// Include a line in your source file for each interface implemented.
GZ_ADD_PLUGIN(
    UnitreePlugin,
    gz::sim::System,
    UnitreePlugin::ISystemPostUpdate,
    UnitreePlugin::ISystemPreUpdate,
    UnitreePlugin::ISystemConfigure)
