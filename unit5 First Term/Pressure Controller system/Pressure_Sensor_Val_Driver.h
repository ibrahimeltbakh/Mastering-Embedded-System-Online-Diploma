/*
*************************************************************
*** @file         :Pressure_Sensor_Val_Driver.h
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/


#ifndef PRESSURE_SENSOR_VAL_DRIVER_H_
#define PRESSURE_SENSOR_VAL_DRIVER_H_
#include "state.h"

enum {
    //PRESSURE_SENSOR_States
    PS_reading,
}PS_state_id;

//PRESSURE_SENSOR_INIT
void PS_init();
//PRESSURE_SENSOR_reading_state
STATE_define(PS_reading);


//State Pointer to Function
extern void (*PS_state)();



#endif // PRESSURE_SENSOR_VAL_DRIVER_H_
