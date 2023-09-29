#include "robot_info/robot_info_class.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;
  RobotInfo rInfo =
      RobotInfo(&nh, "Mir100", "567A359", "169.254.5.180", "3.5.8");
  rInfo.publish_data();
  ros::spin();
  return 0;
}
