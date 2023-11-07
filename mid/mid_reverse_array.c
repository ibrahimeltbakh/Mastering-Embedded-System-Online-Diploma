#include<stdio.h>
void reverse_array(int *a,int len);

int main()
{
	int a[] = {1,2,3,4,5},len;
	len = sizeof(a) / sizeof(a[0]);
	reverse_array(a,len);
	return 0;
}
void reverse_array(int *a,int len)
{
	int b[100];
	
	for(int i = 0 ; i<len ; i++)
	{
		b[i] = a[len-i-1]; 
	}
		
	for(int i = 0 ; i<len ; i++)
	{
		printf("%d ",b[i]);
	}
}