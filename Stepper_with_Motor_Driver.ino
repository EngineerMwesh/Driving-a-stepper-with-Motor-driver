/* Copy right reserve
*#Robotics In Kenya
*email: roboticsinkenya@gmail.com
*youtube: Robotics In Kenya
*/
#include <AccelStepper.h>

AccelStepper stepper1(AccelStepper::FULL4WIRE, 2, 3, 4, 5);

 int power = 100; //power to feed the stepper motors
void setup() {
  Serial.begin(9600);
  analogWrite(6, 100);
  analogWrite(7, 100);

  stepper1.setMaxSpeed(100);

//pwm to open open the motor driver H Briges
  analogWrite(6, power );
  analogWrite(7, power );
}

void loop() {
  long positions[2]; // Array of desired stepper positions

  positions[0] = 120;
  positions[1] = 0;
  stepper1.moveTo(positions);
  stepper1.runSpeedToPosition(); // Blocks until all are in position
  delay(1000);

  // Move to a different coordinate
  positions[0] = -120;
  positions[1] = 0;
  stepper1.moveTo(positions);
  stepper1.runSpeedToPosition(); // Blocks until all are in position
  delay(1000);
}
