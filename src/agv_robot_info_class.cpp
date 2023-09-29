#include "robot_info/agv_robot_info_class.h"
#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle, std::string desc,
                           std::string serial, std::string ip,
                           std::string firmware, std::string max_p)
    : RobotInfo::RobotInfo(node_handle, desc, serial, ip, firmware) {
  maximum_payload = max_p;
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
  robot_info_pub.publish(msg);
}