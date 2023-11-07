#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define element_type uint8_t

#define width1 5
element_type uart_buffer[width1];

typedef struct{

    unsigned int length;
    unsigned int count;
    element_type* head;
    element_type* base;
    element_type* tail;

}FIFO_BUF_t;

typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
}FIFO_Status;


FIFO_Status queue_init(FIFO_BUF_t*  FBUF ,element_type* buf ,uint32_t length );
FIFO_Status enqueue(FIFO_BUF_t* FBUF ,element_type item);
FIFO_Status dequeue(FIFO_BUF_t* FBUF ,element_type *item);
FIFO_Status FIFO_IS_FULL(FIFO_BUF_t* FBUF);
FIFO_Status FIFO_IS_empty(FIFO_BUF_t* FBUF);
void FIFO_print(FIFO_BUF_t* FBUF);





#endif // FIFO_H
