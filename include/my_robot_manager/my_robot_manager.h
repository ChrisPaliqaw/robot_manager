#pragma once

#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <string>
#include <memory>

class RobotManager
{
public:
RobotManager(std::shared_ptr<ros::NodeHandle> node_handle);
void odomCallback(const nav_msgs::Odometry::ConstPtr& msg);
private:
std::shared_ptr<ros::NodeHandle> node_handle;
ros::Subscriber odom_subscriber;
};