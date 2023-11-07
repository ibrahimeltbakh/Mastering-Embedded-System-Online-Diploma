#include "DC.h"

//variables

int DC_Speed = 0;



//State Pointer to Function
void (*DC_state)();

void DC_init()
{
    printf("DC Motor Init \n");
}

STATE_define(DC_idle)
{
    // State name
    DC_State_id = DC_idle;
    // State Action
    // call PWM to make speed = DC_Speed


    printf(" DC_idle State: Speed = %d \n " ,DC_Speed);

}
STATE_define(DC_busy)
{
    // State name
    DC_State_id = DC_busy;
     printf(" DC_busy State: Speed = %d \n " ,DC_Speed);
    // State Action
    // call PWM to make speed = DC_Speed
    DC_state = STATE(DC_idle);

}

void DCMotor_Set_speed(int Speed)
{
    DC_Speed = Speed;

    // State check
    (DC_Speed <30 )? (DC_state = STATE(DC_idle)) : (DC_state = STATE(DC_busy));
     printf("CA --------Speed = %d ----------> DC\n ",DC_Speed);

}



