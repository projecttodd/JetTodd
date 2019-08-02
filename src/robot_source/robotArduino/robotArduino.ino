
#include <DualVNH5019MotorShield.h>
#include <ros.h>
#include <std_msgs/Int8.h>
#include <Servo.h>

enum State {LEFT, // is 1
            RIGHT, // is 2 
            FOWARD, // is 3
            BACK, // is 4
            NONE // is 5
            };
enum servoState {SKY,
                MIDDLE,
                BASE
                };
State currState = NONE;
servoState servo_state = BASE;
ros::NodeHandle nh;
Servo servo;
DualVNH5019MotorShield md;


void messageCb( const std_msgs::Int8& input){
  switch(input.data)
  {
    case 1:
      currState = LEFT;
      break;
    case 2:
      currState = RIGHT;
      break;
    case 3:
      currState = FOWARD;
      break;
    case 4:
      currState = BACK;
      break;
    case 5:
      currState = NONE;
      break;
  }
  
}

void otherCb( const std_msgs::Int8& input){
  switch(input.data)
  {
    case 1:
      servo_state = SKY;
      break;
    case 2:
      servo_state = MIDDLE;
      break;
    case 3: 
      servo_state = BASE;
      break;
  }
}
ros::Subscriber<std_msgs::Int8> input("direction_input", &messageCb );
ros::Subscriber<std_msgs::Int8> servoSUB("servo_input", &otherCb );
void setup() { 
  // put your setup code here, to run once:
  md.init();
  nh.initNode();
  nh.subscribe(input);
  nh.subscribe(servoSUB);
  servo.attach(53);
  servo.write(90);
}

void loop() {

  //motor 1  is right
  //motor 2 is left
  switch(currState)
  {
    case LEFT:
    {
      md.setM2Speed(-100);
      md.setM1Speed(-100);
      break;
    }
    case RIGHT:
    {
      md.setM2Speed(100);
      md.setM1Speed(100);
      break;
    }
    case FOWARD:
    {
      md.setM2Speed(100);
      md.setM1Speed(-100);
      break;
    }
    case BACK:
    {
      md.setM2Speed(-100);
      md.setM1Speed(100);
      break;
    }
    case NONE:
    {
      md.setM2Speed(0);
      md.setM1Speed(0);
      break;
    }
  }
  switch(servo_state)
  {
    case SKY:
      servo.write(0);
      break;
    case MIDDLE:
      servo.write(45);
      break;     
    case BASE:
      servo.write(90);
      break;
  }
 nh.spinOnce();
 delay(1);
}
