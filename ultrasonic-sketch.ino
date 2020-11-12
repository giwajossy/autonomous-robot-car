#include <Drive.h>  //Include the Motor Shield Drive library
#include <HCSR04.h>  //Include the Ultrasonic Sensor library

//Define L298N pin mappings (The MOTOR SHIELD is also called L298N)
const int IN1 = D5;
const int IN2 = D6;
const int IN3 = D7;
const int IN4 = D8;

Drive drive(IN1, IN2, IN3, IN4);  //Create an instance of the function

HCSR04 hc(D1, D2); //Trigger is in port D1, Echo is in port D2

void setup() {

}

void loop() {
  // put your main code here, to run repeatedly:
  if (hc.dist() > 25 ) {
      drive.moveForward(500);
    }
  else {
      drive.stopMoving();
      delay(1000);
      drive.turnLeft(500);
      delay(500);
      drive.stopMoving();
      delay(1000);
    }
}