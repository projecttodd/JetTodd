#include <ros/ros.h>
#include <geomety_msgs/Twist.h>

int main(int argc, char **argv){
    ros::init(argc, argv, "motor_control");
    ros::NodeHandle nh;
    ros::Publisher vel_pub;
    geometry_msgs::Twist vel_msg;
    vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    while (ros::ok()){
        ROS_INFO("Forward");
        vel_msg.linear.x = 1.0;
        vel_msg.angular.z = 0;
        vel_pub.publish(vel_msg);
        ros::Duration(1.0).sleep();

        ROS_INFO("Backward");
        vel_msg.linear.x = -0.8;
        vel_msg.angular.z = 0;
        vel_pub.publish(vel_msg);
        ros::Duration(1.0).sleep();

        ROS_INFO("Left Turn");
        vel_msg.linear.x = 0;
        vel_msg.angular.z = 2.0;
        vel_pub.publish(vel_msg);
        ros::Duration(1.0).sleep();

        ros::spinOnce();
    }

}
