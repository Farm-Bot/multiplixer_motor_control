#ifndef run_motor_h
#define run_motor_h

#include "Arduino.h"


class run_motor
{
  public:
    run_motor(int s0,int s1,int s2,int z,int pwm_left , int pwm_right );
    set();
    motor(int motor,int direction ,int speedd);


    int pool_rate = 50;
    int m1=1;int m2=2; int m3=3; int m4=4;int c_z;
    int forward = 1;
    int backward = 0;
    int motor_speed = 255;

  private:
    int selectPins[3];
    int c_pwm_left;int c_pwm_right;

    const int DELAY_TIME = ((float)pool_rate/512.0)*1000;

};

#endif
