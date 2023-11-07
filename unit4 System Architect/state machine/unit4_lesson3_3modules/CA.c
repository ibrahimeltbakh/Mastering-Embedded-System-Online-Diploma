#include "CA.h"

//variables

int CA_Speed = 0;
int CA_distance = 0;
int CA_threshold = 7;


//State Pointer to Function
void (*CA_state)();


STATE_define(CA_Waiting)
{
    // State name
    CA_State_id = CA_Waiting;
    printf(" CA_Waiting State: distance = %d ,Speed = %d \n " ,CA_distance ,CA_Speed);
    // State Action
    CA_Speed = 0;
    //DC_Motor(CA_Speed)
    DCMotor_Set_speed(CA_Speed);


}
STATE_define(CA_Driving)
{
    // State name
    CA_State_id = CA_Driving;
    printf("CA_Driving State: distance = %d ,Speed = %d \n " ,CA_distance ,CA_Speed);
    // State Action
    CA_Speed = 30;
    //DC_Motor(CA_Speed);
    DCMotor_Set_speed(CA_Speed);


}

void US_Set_distance(int distance)
{
    CA_distance = distance;
    // State check
    // US_GET_distance(CA_distance)
    (CA_distance <= CA_threshold )? (CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
    printf("US --------distance = %d ----------> CA \n",CA_distance);

}


