#include <DualVNH5019MotorShield.h>
#include <ros.h>
#include <std_msgs/Int8.h>

enum State {LEFT, // is 1
            RIGHT, // is 2 
            FOWARD, // is 3
            BACK, // is 4
            NONE // is 5
            };

enum State currState = NONE;

ros::NodeHandle nh;

DualVNH5019MotorShield md;


void messageCb( const std_msgs::Int8& input, State& currState){
  switch(input.data)
  {
    case 1:
      currState = LEFT;
    case 2:
      currState = RIGHT;
    case 3:
      currState = FOWARD;
    case 4:
      currState = BACK;
    case 5:
      currState = NONE;
  }
     
}

ros::Subscriber<std_msgs::Int8> input("direction_input", &messageCb );

void setup() {
  // put your setup code here, to run once:
  md.init();
  nh.initNode();
  nh.subscribe(input);
}

void loop() {

  //motor 1  is right
  //motor 2 is left
  switch(currState)
  {
    case LEFT:
    {
      md.setM2Speed(-200);
      md.setM1Speed(200);
    }
    case RIGHT:
    {
      md.setM2Speed(200);
      md.setM1Speed(-200);
    }
    case FOWARD:
    {
      md.setM2Speed(200);
      md.setM1Speed(200);
    }
    case BACK:
    {
      md.setM2Speed(-200);
      md.setM1Speed(-200);
    }
    case NONE:
    {
      md.setM2Speed(0);
      md.setM1Speed(0);
    }
  }

 nh.spinOnce();
 delay(1);
}
