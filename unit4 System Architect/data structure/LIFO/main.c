
#include "LIFO.h"


unsigned int buffer1[5];





int main()
{
    int i ,temp = 0;
    LIFO_BUF_t UART_Buf, I2C_Buf;
    LIFO_init(&UART_Buf,buffer1,5);
    unsigned int buffer2 = (unsigned int*)malloc(5);
    LIFO_init(&I2C_Buf,buffer2,5);

    for(i = 0 ; i<5 ; i++)
    {
      if(push(&UART_Buf,i) == LIFO_no_error)
       printf("UART_LIFO_Add %d \n",i);

    }
    for(i = 0 ; i<5 ; i++)
    {
      if(pop(&UART_Buf,&temp) == LIFO_no_error)
       printf("UART_LIFO_get %d \n",temp);

    }


    return 0;
}
