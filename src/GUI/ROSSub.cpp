#include "ros/ros.h"
#include "std_msgs/String.h"
#include <fstream>
#include <string>

ofstream file("out.txt");
string message;
void messageCallback(const std_msgs::String::ConstPtr& msg)
{
  message = msg.data;
  file.open();
  file << message;
  file.close();
}

int main(int argc, char **argv)
{

  ros::init(argc, argv "main6");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/message", 1000, messageCallback);
  ros::spin();
  return 0;
}
