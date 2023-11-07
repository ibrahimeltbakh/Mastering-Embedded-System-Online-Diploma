#include<stdio.h>

int sum_digits(int n);

int main()
{
	int dig;
	printf("Enter Digits : ");
	scanf("%d",&dig);
	printf("sum = %d",sum_digits(dig));
	
	return 0;
}
int sum_digits(int n)
{
	int sum =0;
	
	while(n!=0)
	{
		sum = sum + n%10;
		n/=10;
	}
	return sum;
}