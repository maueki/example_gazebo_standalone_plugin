#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo_client.hh>

#include "velocity.pb.h"

int main(int _argc, char **_argv)
{
  // Load gazebo
  gazebo::client::setup(_argc, _argv);

  // Create our node for communication
  gazebo::transport::NodePtr node(new gazebo::transport::Node());
  node->Init();

  auto adv = node->Advertise<standalone_plugin::msgs::Velocity>("/velocity");

  gazebo::common::Time::MSleep(1000);
  standalone_plugin::msgs::Velocity vel;
  vel.set_vel(1);
  adv->Publish(vel);

  // Make sure to shut everything down.
  gazebo::client::shutdown();
}
