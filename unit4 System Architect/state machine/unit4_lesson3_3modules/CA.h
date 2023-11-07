#ifndef CA_H_
#define CA_H_


#include "state.h"

enum{
    CA_Waiting,
    CA_Driving
}CA_State_id;

//State Functions
STATE_define(CA_Waiting);
STATE_define(CA_Driving);

//State Pointer to Function
extern void (*CA_state)();




#endif // CA_H_
