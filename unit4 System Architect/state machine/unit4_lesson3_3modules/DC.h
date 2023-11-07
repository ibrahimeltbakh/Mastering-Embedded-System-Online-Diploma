#ifndef DC_H_
#define DC_H_


#include "state.h"

enum{
    DC_idle,
    DC_busy
}DC_State_id;

//State Functions
STATE_define(DC_idle);
STATE_define(DC_busy);

//State Pointer to Function
extern void (*DC_state)();

void DC_init();


#endif // DC_H_
