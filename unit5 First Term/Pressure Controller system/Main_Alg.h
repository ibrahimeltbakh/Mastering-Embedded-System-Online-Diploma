/*
*************************************************************
*** @file         :Main_Alg.h
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/

#ifndef MAIN_ALG_H_
#define MAIN_ALG_H_
#include "state.h"

enum {
    //Main_Alg_State
    Pressure_Val_Detection
}MA_state_id;

//Main_Alg_Pressure_Val_Detection_State
STATE_define(Pressure_Val_Detection);



//State Pointer to Function
extern void (*MA_state)();


#endif // MAIN_ALG_H_
