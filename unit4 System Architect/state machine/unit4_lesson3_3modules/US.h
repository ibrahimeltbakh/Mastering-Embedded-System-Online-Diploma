#ifndef US_H_
#define US_H_

#include "state.h"

enum{
    US_busy,
}US_State_id;

//State Functions
STATE_define(US_busy);
int US_GET_distance_random(int l , int r , int count);


void US_init();

//State Pointer to Function
extern void (*US_state)();




#endif // US_H_
