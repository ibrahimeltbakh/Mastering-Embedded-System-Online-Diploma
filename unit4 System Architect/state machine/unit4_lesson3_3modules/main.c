#include "CA.h"
#include "US.h"
#include "DC.h"


void Setup()
{
    // init all drivers
    // init IRQ
    // init HAL US_driver MC_driver
    // init Block
    US_init();
    DC_init();
    // set State pointer for each block
    CA_state = STATE(CA_Waiting);
    US_state = STATE(US_busy);
    DC_state = STATE(DC_idle);

}
void main()
{
    volatile int d;
    Setup();

    while(1)
    {
        //  call State for each Block
        US_state();
        CA_state();
        DC_state();
        // wait
        for(d = 0 ; d<=1000 ; d++);

    }
}
