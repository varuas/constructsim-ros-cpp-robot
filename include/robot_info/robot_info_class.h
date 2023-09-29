#pragma once
#include <ros/ros.h>

class RobotInfo {
public:
  RobotInfo(ros::NodeHandle *node_handle, std::string desc, std::string serial,
            std::string ip, std::string firmware);
  virtual void publish_data();

protected:
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;
  ros::Publisher robot_info_pub;

private:
  ros::NodeHandle *nh;
};
