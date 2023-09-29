#include "robot_info/agv_robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>
#include <string>

// Overloaded Constructors - one with hydraulic monitor, and one without
AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle, std::string desc,
                           std::string serial, std::string ip,
                           std::string firmware, std::string max_p)
    : RobotInfo::RobotInfo(node_handle, desc, serial, ip, firmware) {
  maximum_payload = max_p;
}

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle, std::string desc,
                           std::string serial, std::string ip,
                           std::string firmware, std::string max_p,
                           std::string hyd_temp, std::string hyd_fill_level,
                           std::string hyd_pressure)
    : RobotInfo::RobotInfo(node_handle, desc, serial, ip, firmware) {
  maximum_payload = max_p;
  hydraulic_sys_monitor =
      HydraulicSystemMonitor(hyd_temp, hyd_fill_level, hyd_pressure);
}

void AGVRobotInfo::publish_data() {
  while (robot_info_pub.getNumSubscribers() < 1) {
    // wait for a connection to publisher
  }
  robotinfo_msgs::RobotInfo10Fields msg;
  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;
  msg.data_field_05 = "maximum_payload: " + maximum_payload;
  msg.data_field_06 =
      "hydraulic_oil_temperature: " + hydraulic_sys_monitor.getOilTemp();
  msg.data_field_07 = "hydraulic_oil_tank_fill_level: " +
                      hydraulic_sys_monitor.getOilFillLevel();
  msg.data_field_08 =
      "hydraulic_oil_pressure: " + hydraulic_sys_monitor.getOilPressure();
  robot_info_pub.publish(msg);
}