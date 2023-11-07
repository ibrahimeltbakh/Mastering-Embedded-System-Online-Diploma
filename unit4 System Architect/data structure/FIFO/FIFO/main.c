#include "FIFO.h"

int main()
{
    FIFO_BUF_t FIFO_UART;
    element_type i,temp=0;


    if(queue_init(&FIFO_UART,uart_buffer,5) == FIFO_no_error )
        printf("FIFO INIT ----------DONE :) \n");

    for(i=0 ; i<7 ; i++)
    {
        printf("FIFO ENQUEUE (%x) \n ",i);
        if(enqueue(&FIFO_UART,i) == FIFO_no_error )
        {
            printf("FIFO ENQUEUE-----------DONE :) \n");
        }
        else
             printf("FIFO ENQUEUE-----------FAILED :( \n");

    }
    FIFO_print(&FIFO_UART);


    if(dequeue(&FIFO_UART,&temp) == FIFO_no_error )
    {
        printf("FIFO DEQUEUE (%x) -----------DONE :) \n",temp);
    }
        if(dequeue(&FIFO_UART,&temp) == FIFO_no_error )
    {
        printf("FIFO DEQUEUE (%d) -----------DONE :) ",temp);
    }
    FIFO_print(&FIFO_UART);

    return 0;
}
