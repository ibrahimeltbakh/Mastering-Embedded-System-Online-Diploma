#ifndef CA_H_
#define CA_H_

#include <stdio.h>
#include <stdlib.h>
#include "state.h"

enum{
    CA_Waiting,
    CA_Driving
}CA_State_id;

//State Functions
STATE_define(CA_Waiting);
STATE_define(CA_Driving);
int US_GET_distance_random(int l , int r , int count);

//State Pointer to Function
extern void (*CA_state)();




#endif // CA_H_
