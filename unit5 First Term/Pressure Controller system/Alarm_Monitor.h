/*
*************************************************************
*** @file         :Alarm_Monitor.h
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "state.h"

enum {
    //ALARM_ACTUATOR_States
    AM_Alarm_OFF,
    AM_Alarm_ON
}AM_state_id;


//ALARM_MONITOR_Alarm_OFF_State
STATE_define(AM_Alarm_OFF);

//ALARM_MONITOR_Alarm_ON_State
STATE_define(AM_Alarm_ON);

//State Pointer to Function
extern void (*AM_state)();



#endif // ALARM_MONITOR_H_
