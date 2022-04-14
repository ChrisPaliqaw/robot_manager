#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <string>
#include <memory>
#include "../include/my_robot_manager/my_robot_manager.h"

using namespace std;

void RobotManager::odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  float x = msg->pose.pose.position.x;
  float y = msg->pose.pose.position.y;
  ROS_INFO_STREAM("x = " << x << "y = " << y);
  //ros::Duration(1).sleep();
}

RobotManager::RobotManager(shared_ptr<ros::NodeHandle> node_handle): node_handle(node_handle)
{
  odom_subscriber = node_handle->subscribe("robot1/odom", 1000, &RobotManager::odomCallback, this);
}



int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "robot_listener");

  auto n = make_shared<ros::NodeHandle>();

  RobotManager robot_manager(n);

  
  
  ros::spin();

  return 0;
}