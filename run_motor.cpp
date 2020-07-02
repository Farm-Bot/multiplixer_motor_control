#include "Arduino.h"
#include "run_motor.h"

run_motor::run_motor(int s0,int s1,int s2,int z,int pwm_left , int pwm_right )
{
  selectPins[0] = s0;
  selectPins[1] = s1;
  selectPins[2] = s2;
  c_z = z;
  c_pwm_left = pwm_left;
  c_pwm_right = pwm_right;
}

run_motor::set()
{
  for (int i=0; i<3; i++)
  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], LOW);
  }
  pinMode(c_z, OUTPUT);
  pinMode(c_pwm_left, OUTPUT);
  pinMode(c_pwm_right, OUTPUT);

}

run_motor::motor(int motor,int direction ,int speedd)
{
     //////pin_select(motor,direction)///////////////
     int pin;

      if (motor == m1 && direction == forward)
         pin = 0;
      else if (motor == m1 && direction == backward)
         pin = 1;
      else if (motor == m2 && direction == forward)
         pin = 2;
      else if (motor == m2 && direction == backward)
         pin = 3;
      else if (motor == m3 && direction == forward)
         pin = 4;
      else if (motor == m3 && direction == backward)
         pin = 5;
      else if (motor == m4 && direction == forward)
         pin = 6;
      else if (motor == m4 && direction == backward)
         pin = 7;

        ///////////selectMuxPin(pin);//////////////////////////
        if (pin > 7) return; // Exit if pin is out of scope
        for (int i=0; i<3; i++)
        {
           if (pin & (1<<i))
           digitalWrite(selectPins[i], HIGH);
           else
           digitalWrite(selectPins[i], LOW);
        }

     analogWrite(c_z, motor_speed);
     delayMicroseconds(DELAY_TIME);
///////////////////////////////////////////////////////////////////////////////
     /////////////////pin_speed(motor,speedd)//////////////////////////
     if(motor == m1 || m3)
      analogWrite(c_pwm_left, speedd);
     else if (motor == m2 || m4)
      analogWrite(c_pwm_right,speedd);
}





//
// const int selectPins[3] = {2, 3, 4}; // S0~2, S1~3, S2~4
// const int zOutput = 5; // Connect common (Z) to 5 (PWM-capable)
//
// const int LED_ON_TIME = 500; // Each LED is on 0.5s
// const int DELAY_TIME = ((float)LED_ON_TIME/512.0)*1000;
// void setup()
// {
//   // Set up the select pins, as outputs
//   for (int i=0; i<3; i++)
//   {
//     pinMode(selectPins[i], OUTPUT);
//     digitalWrite(selectPins[i], LOW);
//   }
//   pinMode(zOutput, OUTPUT); // Set up Z as an output
// }
//
// void loop()
// {
//   // Cycle from pins Y0 to Y7 first
//   for (int pin=0; pin<=7; pin++)
//   {
//     // Set the S0, S1, and S2 pins to select our active
//     // output (Y0-Y7):
//     selectMuxPin(pin);
//     // While the output is selected ramp the LED intensity up
//     for (int intensity=0; intensity<=255; intensity++)
//     {
//       analogWrite(zOutput, intensity);
//       delayMicroseconds(DELAY_TIME);
//     }
//
//   }
//   // Now cycle from pins Y6 to Y1
//   for (int pin=6; pin>=1; pin--)
//   {
//     selectMuxPin(pin); // Select the pin
//     // Cycle the intensity up:
//     for (int intensity=0; intensity<=255; intensity++)
//     {
//       analogWrite(zOutput, intensity);
//       delayMicroseconds(DELAY_TIME);
//     }
//     // Then ramp the output down:
//     for (int intensity=255; intensity>=0; intensity--)
//     {
//       analogWrite(zOutput, intensity);
//       delayMicroseconds(DELAY_TIME);
//     }
//   }
// }
//
// // The selectMuxPin function sets the S0, S1, and S2 pins
// // accordingly, given a pin from 0-7.
// void selectMuxPin(byte pin)
// {
//   if (pin > 7) return; // Exit if pin is out of scope
//   for (int i=0; i<3; i++)
//   {
//     if (pin & (1<<i))
//       digitalWrite(selectPins[i], HIGH);
//     else
//       digitalWrite(selectPins[i], LOW);
//   }
// }
