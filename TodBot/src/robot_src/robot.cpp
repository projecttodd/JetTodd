#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
int8 input;
input = 5;
int main(int argc, char **argv)
{
  sf::RenderWindow window(sf::VideoMode(500,500), "Controls");
  ros::init(argc, argv, "robot")
  ros::NodeHandle n;

  ros::Publisher input_pub = n.advertise<std_msgs::Int8>("direction_input", 1000);
  ros::Rate loop_rate(10);
  while (window.isOpen())
  {
    while(ros::ok())
    {
      sf::Event event;
      std_msgs::Int8 msg;

      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
          window.close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        input = 1;
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
          input = 2;
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
          input = 3;
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
          input = 4;
      else if (!sf::Keyboard::isKeyPressed())
          input = 5;

      msg.data = input;
      input_pub.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
    }
  }
  return 0;
}
