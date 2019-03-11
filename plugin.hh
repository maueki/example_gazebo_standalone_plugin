#pragma once

#include <gazebo/common/Plugin.hh>
#include <gazebo/common/UpdateInfo.hh>
#include <gazebo/transport/transport.hh>

#include <boost/shared_ptr.hpp>

#include <atomic>
#include <cstdint>

#include "velocity.pb.h"

namespace gazebo
{

using MsgVelocityPtr = const boost::shared_ptr<const standalone_plugin::msgs::Velocity>;

class GAZEBO_VISIBLE StandalonePlugin : public ModelPlugin
{
    event::ConnectionPtr update_conn_;
    physics::ModelPtr model_;
    transport::NodePtr node_;
    transport::SubscriberPtr sub_;

    std::atomic<int32_t> vel_ = 0;
public:
    StandalonePlugin();
    ~StandalonePlugin();

    void Load(physics::ModelPtr model, sdf::ElementPtr _sdf) override;
    void Reset() override;

    void OnUpdate();

    void CbMsgVelocity(MsgVelocityPtr& recv_vel);
};

}
