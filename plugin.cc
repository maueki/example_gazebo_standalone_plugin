#include "plugin.hh"
#include <gazebo/common/Events.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/Link.hh>

namespace gazebo {

GZ_REGISTER_MODEL_PLUGIN(StandalonePlugin)

StandalonePlugin::StandalonePlugin(){}
StandalonePlugin::~StandalonePlugin(){}

void StandalonePlugin::Load(physics::ModelPtr model, sdf::ElementPtr _sdf)
{
    gzmsg << "Load StandalonePlugin\n";

    update_conn_ = event::Events::ConnectWorldUpdateBegin(std::bind(&StandalonePlugin::OnUpdate, this));
    model_ = model;

    node_ = gazebo::transport::NodePtr(new gazebo::transport::Node());
    node_->Init();

    sub_ = node_->Subscribe("/velocity", &StandalonePlugin::CbMsgVelocity, this);

}

void StandalonePlugin::OnUpdate() {
    model_->GetJoint("front_right")->SetVelocity(0, vel_);
    model_->GetJoint("front_left")->SetVelocity(0, vel_);
    model_->GetJoint("rear_right")->SetVelocity(0, vel_);
    model_->GetJoint("rear_left")->SetVelocity(0, vel_);
}

void StandalonePlugin::Reset() {
}

void StandalonePlugin::CbMsgVelocity(MsgVelocityPtr& recv_vel) {
    vel_ = recv_vel->vel();
}

}
