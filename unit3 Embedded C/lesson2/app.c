#include"Uart.h"
unsigned char String_buffer[100] = "learn-in-depth<ibrahim_eltbakh>";

void main(void)
{
	Uart_Send_String(String_buffer); 
}