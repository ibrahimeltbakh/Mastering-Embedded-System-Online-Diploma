/*
*************************************************************
*** @file         :Pressure_Sensor_Val_Driver.c
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/

#include "Pressure_Sensor_Val_Driver.h"

int PVal=0;

//State Pointer to Function
void (*PS_state)();

//PRESSURE_SENSOR_INIT
void PS_init()
{
   // printf("PS_init \n");
}
//PRESSURE_SENSOR_reading_state
STATE_define(PS_reading)
{
    // State name
    PS_state_id= PS_reading;
   // printf("Pressure Sensor reading State \n" );

    PVal = getPressureVal();
    Set_Pressure(PVal);
}





