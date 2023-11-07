/*
*************************************************************
*** @file         :main.c
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/

#include "Pressure_Sensor_Val_Driver.h"
#include "Main_Alg.h"
#include "Alarm_Monitor.h"
#include "Alarm_Actuator_Driver.h"
#include "driver.h"


void Setup()
{
    // init all drivers
	GPIO_INITIALIZATION();
    
    // init Block
    PS_init();
    AA_init();
    // set State pointer for each block
    PS_state = STATE(PS_reading);
    MA_state = STATE(Pressure_Val_Detection);
    AM_state = STATE(AM_Alarm_OFF);
    AA_state = STATE(AA_Waiting);

}
void main()
{
    volatile int i;
    Setup();

    while(1)
    {
        //  call State for each Block

        PS_state();
        MA_state();
        AM_state();
        AA_state();


   // printf("Init Timer For 100s \n");
    // init timer for 100s
    Delay(10000);

    }
}

