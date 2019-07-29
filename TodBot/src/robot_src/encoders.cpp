#include <ros/ros.h>
#include "std_msgs/UInt64.h"

int callback_ticks = 0;
int total_rotation = 0;
std_msgs::UInt64 msg;

void left_encoder_callback(const std_msgs::UInt64::ConstPtr& msg){
  callback_ticks = msg->data;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "motor_encoder_example");
    ros::NodeHandle nh;

    ros::Subscriber left_encoder_sub = nh.subscribe("/arduino/encoder_left_value", 10, &left_encoder_callback);

    while (ros::ok()) {
        ROS_INFO("Forward");
        total_rotation += callback_ticks;
        callback_ticks = 0;
        ROS_INFO("Total rotation: %d", total_rotation);
        ros::Duration(5.0).sleep();

        ROS_INFO("Forward");
        total_rotation -= callback_ticks;
        callback_ticks = 0;
        ROS_INFO("Total rotation: %d", total_rotation);
        ros::Duration(5.0).sleep();

        ros::spinOnce();
    }

  }
