#include "Arduino.h"
#include "run_motor.h"

run_motor::run_motor(int m_left_1,int m_left_2,int m_right_1,int m_right_2,int pwm_left , int pwm_right )
{
     c_m_left_1 = m_left_1;
     c_m_left_2 = m_left_2;
     c_m_right_1 = m_right_1;
     c_m_right_2 = m_right_2;
     c_pwm_left = pwm_left;
     c_pwm_right = pwm_right;
}

run_motor::set()
{

     pinMode(c_m_left_1, OUTPUT);
     pinMode(c_m_left_2, OUTPUT);
     pinMode(c_m_right_1, OUTPUT);
     pinMode(c_m_right_2, OUTPUT);

     pinMode(c_pwm_left, OUTPUT);
     pinMode(c_pwm_right, OUTPUT);

}

run_motor::motor(int direction ,int speedd)
{
     if(direction == forward){
          digitalWrite(c_m_left_1,HIGH);
          digitalWrite(c_m_left_2,LOW);
          digitalWrite(c_m_right_1,HIGH);
          digitalWrite(c_m_right_2,LOW);
          analogWrite(c_pwm_left,speedd);
          analogWrite(c_pwm_right,speedd);
     }
     else if(direction == backward){
          digitalWrite(c_m_left_1,LOW);
          digitalWrite(c_m_left_2,HIGH);
          digitalWrite(c_m_right_1,LOW);
          digitalWrite(c_m_right_2,HIGH);
          analogWrite(c_pwm_left,speedd);
          analogWrite(c_pwm_right,speedd);
     }
     else if(direction == left){
          digitalWrite(c_m_left_1,HIGH);
          digitalWrite(c_m_left_2,LOW);
          digitalWrite(c_m_right_1,HIGH);
          digitalWrite(c_m_right_2,LOW);
          analogWrite(c_pwm_left,speedd/turn_rate);
          analogWrite(c_pwm_right,speedd);
     }
     else if(direction == right){
          digitalWrite(c_m_left_1,HIGH);
          digitalWrite(c_m_left_2,LOW);
          digitalWrite(c_m_right_1,HIGH);
          digitalWrite(c_m_right_2,LOW);
          analogWrite(c_pwm_left,speedd);
          analogWrite(c_pwm_right,speedd/turn_rate);
     }
     else if(direction == stop){
          digitalWrite(c_m_left_1,LOW);
          digitalWrite(c_m_left_2,LOW);
          digitalWrite(c_m_right_1,LOW);
          digitalWrite(c_m_right_2,LOW);
          analogWrite(c_pwm_left,0);
          analogWrite(c_pwm_right,0);
     }
     else {
          digitalWrite(c_m_left_1,LOW);
          digitalWrite(c_m_left_2,LOW);
          digitalWrite(c_m_right_1,LOW);
          digitalWrite(c_m_right_2,LOW);
          analogWrite(c_pwm_left,0);
          analogWrite(c_pwm_right,0);
     }
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
