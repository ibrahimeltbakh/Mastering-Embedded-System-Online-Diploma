#ifndef STATE_H_
#define STATE_H_


// generate state functions automatic
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_)  ST_##_stateFUN_



#endif // STATE_H_
