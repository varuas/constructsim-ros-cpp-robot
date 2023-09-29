#include "robot_info/agv_robot_info_class.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");
  ros::NodeHandle nh;
  AGVRobotInfo rInfo =
      AGVRobotInfo(&nh, "Mir100", "567A359", "169.254.5.180", "3.5.8", "100 Kg",
                   "45C", "100%", "250 bar");
  rInfo.publish_data();
  ros::spin();
  return 0;
}
