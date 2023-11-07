#ifndef LIFO_H
#define LIFO_H

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    unsigned int length;
    unsigned int* base;
    unsigned int* head;
    unsigned int count;

}LIFO_BUF_t;

typedef enum
{
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_null

}LIFO_Status;


LIFO_Status push(LIFO_BUF_t* lBuf, unsigned int item);
LIFO_Status pop(LIFO_BUF_t* lBuf, unsigned int* item);
LIFO_Status LIFO_init(LIFO_BUF_t* lBuf, unsigned int* buf , unsigned int length);






















#endif
