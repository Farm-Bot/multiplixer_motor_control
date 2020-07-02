This example code is in the public domain.


 This library uses 4051 mux ic to operate 4 DC motor individually with PWM support.
 The motors can be driven by a motor driver with enable pin

 ***PIN CONNECTION***

  4051 - S0 ----> 2
  4051 - S1 ----> 3
  4051 - S2 ----> 4
  4051 - z  ----> 9
  motor driver enable pin m1 ----> 10
  motor driver enable pin m2 ----> 11
  motor driver enable pin m3 ----> 10
  motor driver enable pin m4 ----> 11

motor configuration
m1 [-------] m2
   |       |
   |       |
   |       |
   |       |
m3 [-------] m4
