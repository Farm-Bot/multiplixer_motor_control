#ifndef run_motor_h
#define run_motor_h

#include "Arduino.h"


class run_motor
{
  public:
    run_motor(int m_left_1,int m_left_2,int m_right_1,int m_right_2,int pwm_left , int pwm_right ); //pwm_left,pwm_right,ml1,ml2,mr1,mr2
    set();
    motor(int direction,int speedd);


    int forward = 1, backward = -1, left = 2, right = 3, stop = 0, speedd = 255;
    int turn_rate = 2;

  private:
    int c_m_left_1, c_m_left_2, c_m_right_1, c_m_right_2;
    int c_pwm_left,c_pwm_right;

};

#endif
