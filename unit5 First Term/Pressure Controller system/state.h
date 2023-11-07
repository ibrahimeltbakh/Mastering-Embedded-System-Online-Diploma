/*
*************************************************************
*** @file         :state.h
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "driver.h"

// generate state functions automatic
#define STATE_define(_stateFUN_) void PS_##_stateFUN_()
#define STATE(_stateFUN_)  PS_##_stateFUN_

//states Connection
void Set_Pressure(int ps_val);
void High_Pressure_Detected();
void Start_Alarm();
void Stop_Alarm();



#endif // STATE_H_
