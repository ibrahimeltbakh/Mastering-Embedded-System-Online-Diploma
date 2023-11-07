
#include "LIFO.h"

LIFO_Status push(LIFO_BUF_t* lBuf, unsigned int item)
{
    //check lifo is valid
    if(!lBuf->head || !lBuf->base)
        return LIFO_null;
    //check lifo full
    // if(lBuf->head >= (lBuf->base + (lBuf->length*sizeof(unsigned char))))
    if(lBuf->count == lBuf->length)
        return LIFO_full;
    //add item
    *(lBuf->head) = item;
    lBuf->head++;
    lBuf->count++;

    return LIFO_no_error;

}

LIFO_Status pop(LIFO_BUF_t* lBuf, unsigned int* item)
{
    //check lifo is valid
    if(!lBuf->head || !lBuf->base)
        return LIFO_null;
    //check lifo empty
    if(lBuf->count == 0)
        return LIFO_empty;
    //get item
    lBuf->head--;
    *item = *(lBuf->head);

    lBuf->count--;

    return LIFO_no_error;

}
LIFO_Status LIFO_init(LIFO_BUF_t* lBuf, unsigned int* buf , unsigned int length)
{
    if(lBuf == NULL)
        return LIFO_null;

    lBuf->base = buf;
    lBuf->head = buf;
    lBuf->length = length;
    lBuf->count =0;


}
