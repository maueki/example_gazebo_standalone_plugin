#include "plugin.hh"
#include <gazebo/common/Events.hh>

namespace gazebo {

GZ_REGISTER_MODEL_PLUGIN(StandalonePlugin)

StandalonePlugin::StandalonePlugin(){}
StandalonePlugin::~StandalonePlugin(){}

void StandalonePlugin::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
{
    gzmsg << "Load StandalonePlugin\n";

    update_conn_ = event::Events::ConnectWorldUpdateBegin(std::bind(&StandalonePlugin::OnUpdate, this));
}

void StandalonePlugin::OnUpdate() {
    gzmsg << "call OnUpdate\n";
}

void StandalonePlugin::Reset() {
}

}
