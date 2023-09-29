#pragma once
#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle *node_handle, std::string desc,
               std::string serial, std::string ip, std::string firmware,
               std::string max_p);
  AGVRobotInfo(ros::NodeHandle *node_handle, std::string desc,
               std::string serial, std::string ip, std::string firmware,
               std::string max_p, std::string hyd_temp,
               std::string hyd_fill_level, std::string hyd_pressure);
  void publish_data() override;

private:
  std::string maximum_payload;
  HydraulicSystemMonitor hydraulic_sys_monitor;
};