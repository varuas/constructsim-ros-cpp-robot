#pragma once
#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle *node_handle, std::string desc,
               std::string serial, std::string ip, std::string firmware,
               std::string max_p);
  void publish_data() override;

private:
  std::string maximum_payload;
};