#include<stdio.h>

int sum_without_loop(int x);
int sum ;
int main()
{
	printf("Res = %d ",sum_without_loop(100));
	return 0;
}

int sum_without_loop(int x)
{
	sum += x;
	x--;
	if(x == 0)
		return sum;
	sum_without_loop(x);
	
}