#include "CA.h"

//variables

int CA_Speed = 0;
int CA_distance = 0;
int CA_threshold = 10;


//State Pointer to Function
void (*CA_state)();

int US_GET_distance_random(int l , int r , int count)
{
    int i ,rand_value;
    for(i = 0 ; i<count ; i++)
    {
        rand_value = (rand() % (r-l+1)) +1;
    }
    return rand_value;
}
STATE_define(CA_Waiting)
{
    // State name
    CA_State_id = CA_Waiting;
    // State Action
    CA_Speed = 0;
    //DC_Motor(CA_Speed);

    // State check
    // US_GET_distance(CA_distance)
    CA_distance = US_GET_distance_random(45 ,55 ,1);
    (CA_distance <= CA_threshold )? (CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
    printf(" CA_Waiting State: distance = %d ,Speed = %d \n " ,CA_distance ,CA_Speed);

}
STATE_define(CA_Driving)
{
    // State name
    CA_State_id = CA_Driving;
    // State Action
    CA_Speed = 30;
    //DC_Motor(CA_Speed);

    // State check
    // US_GET_distance(CA_distance)
    CA_distance = US_GET_distance_random(45 ,55 ,1);
    (CA_distance <= CA_threshold )? (CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
    printf("CA_Driving State: distance = %d ,Speed = %d \n " ,CA_distance ,CA_Speed);
}



