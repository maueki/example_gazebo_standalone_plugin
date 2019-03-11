#pragma once

#include <gazebo/common/Plugin.hh>
#include <gazebo/common/UpdateInfo.hh>

namespace gazebo
{

class GAZEBO_VISIBLE StandalonePlugin : public ModelPlugin
{
    event::ConnectionPtr update_conn_;
public:
    StandalonePlugin();
    ~StandalonePlugin();

    void Load(physics::ModelPtr model, sdf::ElementPtr _sdf) override;
    void Reset() override;

    void OnUpdate();
};

}
