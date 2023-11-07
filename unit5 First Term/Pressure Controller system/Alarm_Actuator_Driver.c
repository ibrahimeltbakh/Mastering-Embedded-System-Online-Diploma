/*
*************************************************************
*** @file         :Alarm_Actuator.c
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/

#include "Alarm_Actuator_Driver.h"

//State Pointer to Function
void (*AA_state)();

//Start_Alarm_signal
void Start_Alarm()
{
   // printf("Alarm_Monitor --------Start_Alarm  ----------> Alarm_Actuator \n");
    //printf("Alarm Started :( \n");
	// LED ON
	Set_Alarm_actuator(0);
    // go to Alarm_on State
    AA_state = STATE(AA_Alarm_ON);
}
//Stop_Alarm_signal
void Stop_Alarm()
{
   //  printf("Alarm_Monitor -------- Stop_Alarm  ----------> Alarm_Actuator \n");
    // printf("Alarm Stoped :) \n");
	// LED OFF
	Set_Alarm_actuator(1);
    // go to Alarm_OFF State
   AA_state =  STATE(AA_Alarm_OFF);
}
//ALARM_ACTUATOR_INIT_fun
void AA_init()
{
  //  printf("Alarm_Actuator INIT \n");
}
//ALARM_ACTUATOR_Waiting_State_fun
STATE_define(AA_Waiting)
{
    AA_state_id = AA_Waiting;
   // printf("Alarm_Actuator_Waiting State \n");
   Set_Alarm_actuator(1);

}
//ALARM_ACTUATOR_Alarm_ON_State_fun
STATE_define(AA_Alarm_ON)
{
    AA_state_id = AA_Alarm_ON;
  //  printf("Alarm_Actuator_Alarm_ON State : Waiting For 60s \n ");
    //go to waiting State
   AA_state =  STATE(AA_Waiting);
}
//ALARM_ACTUATOR_Alarm_OFF_State_fun
STATE_define(AA_Alarm_OFF)
{
    AA_state_id = AA_Alarm_OFF;
  //  printf("Alarm_Actuator_Alarm_OFF State \n");
	
    //go to waiting State
    AA_state = STATE(AA_Waiting);
}

