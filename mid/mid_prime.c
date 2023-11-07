#include<stdio.h>

int if_prime(int n);

int main()
{
	int x , y ;
	printf("Enter Two Numbers To Search prime between these numbers ");
	scanf("%d %d",&x,&y);
	for(int i=x+1 ; i<y ; i++)
	{
		if(if_prime(i) == 0)
			printf("%d  ",i);
	}
	return 0;
}

int if_prime(int n)
{
	int flag =0 ,i;
	for(i = 2 ; i<=n/2 ; i++)
	{
		if(n %  i== 0 )
		{
			flag = 1;
			break;
		}
	}
	return flag;
}