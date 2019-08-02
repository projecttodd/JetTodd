#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "servo");
  ros::NodeHandle n;

 int input;
  string direction;
  input = 3;
  ros::Publisher servo_pub = n.advertise<std_msgs::Int8>("servo__input", 1000);
  ros::Rate loop_rate(10);
    while(ros::ok())
    {

      std_msgs::Int8 msg;

      cin >> direction;
        if(direction == "R")
                input = 1;
        else if(direction == "T")
                input = 2;
        else if(direction == "Y")
                input = 3;

      msg.data = input;
      servo_pub.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
    }
  
  return 0;
}


