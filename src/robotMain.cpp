#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "robot");
  ros::NodeHandle n;

 int input;
	string direction;
	input = 5;
  ros::Publisher input_pub = n.advertise<std_msgs::Int8>("direction_input", 1000);
  ros::Rate loop_rate(10);
    while(ros::ok())
    {
      
      std_msgs::Int8 msg;
      
      cin >> direction;
	if(direction == "A")
		input = 1;
	else if(direction == "D")
		input = 2;
	else if(direction == "W")
		input = 3;
	else if(direction == "S")
		input = 4;
	else if(direction == "Q")
		input = 5;

      msg.data = input;
      input_pub.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
    }
  
  return 0;
}
