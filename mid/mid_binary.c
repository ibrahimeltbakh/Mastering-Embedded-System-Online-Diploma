#include<stdio.h>

int main()
{
	int n,k,count =0;
	printf("Enter Number : ");
	scanf("%d",&n);
	printf("Your Number In binary = ");
	for(int i = 7 ; i>=0 ; i--)
	{
		k = n>>i;
		
		if(k&1 ){
			printf("1");
			count++;
		}
		else
		{
			printf("0");
		}
			
	}
	printf("\nSo Has %d ones",count);
}