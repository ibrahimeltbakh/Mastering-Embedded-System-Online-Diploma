#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

// generate state functions automatic
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_)  ST_##_stateFUN_

//states Connection
void US_Set_distance(int distance);
void DCMotor_Set_speed(int Speed);



#endif // STATE_H_
