/* run_motor

 This example code is in the public domain.


 This library uses 4051 mux ic to operate 4 DC motor individually with PWM support.


 ***PIN CONNECTION***

  motor controller e1 ----> 2
  motor controller e2 ----> 3
  motor controller m1 ----> 4
  motor controller m2 ----> 5
  motor controller m3 ----> 6
  motor controller m4 ----> 7

motor configuration
m1|m2 [-------] m3|m4
      |       |
      |       |
      |       |
      |       |
m1|m2 [-------] m3|m4
*/

#include<run_motor.h> // includes the libraey

run_motor instance(2,3,4,5,6,7); // call run_motor with a name instance
void setup() {
  instance.set(); // initialize run_motor
  instance.turn_rate = 2; // default = 2 defines how sharp turn the vehical should take
}

void loop() {
  instance.motor(instance.forward,125); // Set vehical to go forward with a speed of 125 out of 255
  instance.motor(instance.backward,255); // Set vehical to go forward with a speed of 125 out of 255
  instance.motor(instance.left,125); // Set vehical to go left with a speed of 125 out of 255
  instance.motor(instance.right,125); // Set vehical to go right with a speed of 125 out of 255
  instance.motor(instance.stop,255); // Set vehical to go stop with a speed is set to 0

}
