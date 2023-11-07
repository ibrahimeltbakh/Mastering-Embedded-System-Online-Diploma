#include "CA.h"



void Setup()
{
    // init all drivers
    // init IRQ
    // init HAL US_driver MC_driver
    // init Block
    // set State pointer for each block
    CA_state = STATE(CA_Waiting);

}
void main()
{
    Setup();

    while(1)
    {
        CA_state();

    }
}
