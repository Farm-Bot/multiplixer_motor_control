/* run_motor

 This example code is in the public domain.


 This library uses 4051 mux ic to operate 4 DC motor individually with PWM support.


 ***PIN CONNECTION***

  4051 - S0 ----> 2
  4051 - S1 ----> 3
  4051 - S2 ----> 4
  4051 - z  ----> 9
  motor controller m1 ----> 10
  motor controller m2 ----> 11
  motor controller m3 ----> 10
  motor controller m4 ----> 11

motor configuration
m1 [-------] m2
   |       |
   |       |
   |       |
   |       |
m3 [-------] m4
*/

#include<run_motor.h> // includes the libraey

run_motor instance(2,3,4,9,10,11); // call run_motor with a name instance
void setup() {
  instance.set(); // initialize run_motor
}

void loop() {
  instance.motor(instance.m1,instance.forward,125); // Set motor m1 to go forward with a speed of 125 out of 255
  instance.motor(instance.m2,instance.backward,255); // Set motor m1 to go forward with a speed of 125 out of 255

}
