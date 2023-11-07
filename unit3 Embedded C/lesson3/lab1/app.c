#include"uart.h"
unsigned char string_buffer[100] = "learn-in-depth<ibrahim_eltbakh>";
unsigned char String_buffer2[100] = "learn-in-depth<ibrahim_eltbakh>";
unsigned char String_buffer3[100] = "learn-in-depth<ibrahim_eltbakh>";
void main()
{
	Uart_Send_String(string_buffer);
}