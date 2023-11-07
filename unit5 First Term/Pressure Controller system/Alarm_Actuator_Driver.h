/*
*************************************************************
*** @file         :Alarm_Actuator.h
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_
#include "state.h"

enum {
    //ALARM_ACTUATOR_States
    AA_Waiting,
    AA_Alarm_ON,
    AA_Alarm_OFF
}AA_state_id;

//ALARM_ACTUATOR_INIT
void AA_init();
//ALARM_ACTUATOR_Waiting_State
STATE_define(AA_Waiting);
//ALARM_ACTUATOR_Alarm_ON_State
STATE_define(AA_Alarm_ON);
//ALARM_ACTUATOR_Alarm_OFF_State
STATE_define(AA_Alarm_OFF);



//State Pointer to Function
extern void (*AA_state)();

#endif // ALARM_ACTUATOR_H_
