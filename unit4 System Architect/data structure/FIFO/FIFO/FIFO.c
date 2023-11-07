#include "FIFO.h"

FIFO_Status queue_init(FIFO_BUF_t*  FBUF ,element_type* buf ,uint32_t length )
{
    //fifo valid
    if(FBUF == NULL)
        return FIFO_null;
    FBUF->base = buf;
    FBUF->head = buf;
    FBUF->tail = buf;
    FBUF->count = 0;
    FBUF->length = length;

    return FIFO_no_error;

}
FIFO_Status enqueue(FIFO_BUF_t* FBUF ,element_type item)
{
    if(!FBUF->head || !FBUF->base || !FBUF->tail)
        return FIFO_null;

    if(FIFO_IS_FULL(FBUF) == FIFO_full)
        return FIFO_full;

        *(FBUF->head) = item;
        FBUF->count++;

        //circler queue
        if(FBUF->head == (FBUF->base + (FBUF->length*sizeof(element_type))))
            FBUF->head = FBUF->base;
        else
            FBUF->head++;

        return FIFO_no_error;


}
FIFO_Status dequeue(FIFO_BUF_t* FBUF ,element_type *item)
{
    if(!FBUF->head || !FBUF->base || !FBUF->tail)
        return FIFO_null;

     if(FIFO_IS_empty(FBUF) == FIFO_empty)
        return FIFO_empty;

        *item = *(FBUF->tail);
        FBUF->count--;

        //circler queue
        if(FBUF->tail == (FBUF->base + (FBUF->length*sizeof(element_type))))
        {
            FBUF->tail = FBUF->base;
        }
        else{
            FBUF->tail++;
        }

        return FIFO_no_error;

}
FIFO_Status FIFO_IS_FULL(FIFO_BUF_t* FBUF)
{
    // check FIFO Valid
    if(!FBUF->head || !FBUF->base || !FBUF->tail)
        return FIFO_null;
    //check FIFO Full
    if(FBUF->count == FBUF->length)
    {
        printf("FIFO IS FULL !!\n");
        return FIFO_full;
    }
    return FIFO_no_error;
}
FIFO_Status FIFO_IS_empty(FIFO_BUF_t* FBUF)
{
    // check FIFO Valid
    if(!FBUF->head || !FBUF->base || !FBUF->tail)
        return FIFO_null;
    //check FIFO Full
    if(FBUF->count == 0)
    {
        printf("FIFO is empty ");
         return FIFO_empty;
    }

    return FIFO_no_error;

}
void FIFO_print(FIFO_BUF_t* FBUF)
{
    element_type* tmp;
    int i;
    if(FBUF->count == 0)
    {
        printf("FIFO IS EMPTY \n");

    }
    else{
        tmp = FBUF->tail;
        printf("\n=======FIFO PRINT========\n");
        for(i = 0 ;i<FBUF->count ;i++)
        {
            printf("    %X \n",*tmp);
            tmp++;
        }
        printf("=========================\n");
    }


}
