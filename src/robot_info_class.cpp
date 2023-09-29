#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>

RobotInfo::RobotInfo(ros::NodeHandle *node_handle, std::string desc,
                     std::string serial, std::string ip, std::string firmware) {

  nh = node_handle;
  robot_description = desc;
  serial_number = serial;
  ip_address = ip;
  firmware_version = firmware;
  robot_info_pub =
      nh->advertise<robotinfo_msgs::RobotInfo10Fields>("/robot_info", 1);
}

void RobotInfo::publish_data() {
  while (robot_info_pub.getNumSubscribers() < 1) {
    // wait for a connection to publisher
  }
  robotinfo_msgs::RobotInfo10Fields msg;
  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;
  robot_info_pub.publish(msg);
}
