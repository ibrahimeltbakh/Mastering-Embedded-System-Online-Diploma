/*
*************************************************************
*** @file         :Main_Alg.c
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/

#include "Main_Alg.h"

int MA_PVal = 0;
int Threshold =20;

//State Pointer to Function
void (*MA_state)();

//Set_Pressure_signal_Fun
void Set_Pressure(int ps_val)
{
    MA_PVal = ps_val;
   // printf("PS --------Pressure_value = %d ----------> Main_Alg \n",MA_PVal);
    // State check
    if(MA_PVal >= Threshold)
    {
        //Send Signal With High Pressure
        High_Pressure_Detected();
        // go to Pressure_Val_Detection state
       // MA_state =  STATE(Pressure_Val_Detection);
       /****************will go from main **********/

    }
    // go to Pressure_Val_Detection state
   // MA_state = STATE(Pressure_Val_Detection);
   /****************will go from main **********/

}


//Main_Alg_Pressure_Val_Detection_State_Fun
STATE_define(Pressure_Val_Detection)
{
    //state name
    MA_state_id = Pressure_Val_Detection;
  //  printf("Main_ALG_Pressure_Val_Detection_state : MA_PVal = %d \n",MA_PVal);
}

