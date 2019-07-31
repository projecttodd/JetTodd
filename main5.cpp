#include <stdio.h>
#include <iostream>
#include <string>
#include <ros/ros.h>
#include <std_msgs/String.h>



int main(int argc, char**argv)
{
  ros::init(argc, argv "main5");
  ros::NodeHandle n;
  ros::Publisher message = n.advertise<std_msgs::String>("/message", 1000);
  ros::Rate loop_rate(10);
  string info;
  int count = 0;
  while (ros::ok()) {

      std::cout << std::endl << std::endl;
      std::cout << "Type your Message Below:" << std::endl << std::endl;
      getline(std::cin, info);

      msg.data = info;
      message.advertise(msg);
    }
}
