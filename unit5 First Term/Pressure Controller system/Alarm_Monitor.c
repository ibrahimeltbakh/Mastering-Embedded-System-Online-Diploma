/*
*************************************************************
*** @file         :Alarm_Monitor.c
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/
#include"Alarm_Monitor.h"
int Alarm_Periode = 6000;
//State Pointer to Function
void (*AM_state)();
//Pressure_Detection_signal
void High_Pressure_Detected()
{
  //  printf("Main_Alg -------- High Pressure Value  ----------> Alarm_Monitor \n");
    // go to alarm on State
    AM_state = STATE(AM_Alarm_ON);
}
//ALARM_MONITOR_Alarm_ON_State_fun
STATE_define(AM_Alarm_ON)
{
    int i;
    //state name
    AM_state_id = AM_Alarm_ON;
    //printf("Alarm_Monitor_Alarm_On_state\n");
    //Send Start Alarm signal
    Start_Alarm();
    //init timer for 60s
    Delay(Alarm_Periode);
    //wait for timer expire
   // printf("Alarm_Monitor_timer expired\n");

    //reset timer
   // printf("Alarm_Monitor_timer reset\n");

    //Send Stop Alarm signal
    Stop_Alarm();

    // go to alarm off state
    AM_state = STATE(AM_Alarm_OFF);
}
//ALARM_MONITOR_Alarm_OFF_State_fun
STATE_define(AM_Alarm_OFF)
{
    AM_state_id = AM_Alarm_OFF;
   // printf("Alarm_Monitor_Alarm_OFF_state\n");
}


