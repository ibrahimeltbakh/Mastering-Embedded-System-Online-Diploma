#include "US.h"

//variables


int US_distance = 0;



//State Pointer to Function
void (*US_state)();

void US_init()
{
    printf("US_init \n");
}

STATE_define(US_busy)
{
    // State name
    US_State_id = US_busy;

    US_distance = US_GET_distance_random(45 ,55 ,1);
    printf(" US_Busy State: distance = %d\n " ,US_distance );

    US_Set_distance(US_distance);
    US_state = STATE(US_busy);


}


int US_GET_distance_random(int l , int r , int count)
{
    int i ,rand_value;
    for(i = 0 ; i<count ; i++)
    {
        rand_value = (rand() % (r-l+1)) +1;
    }
    return rand_value;
}


