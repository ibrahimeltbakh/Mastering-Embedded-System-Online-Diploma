#include<math.h>
#include<stdio.h>

int main()
{
	int x;
	double res;
	
	printf("Enter Value : ");
	scanf("%d",&x);
	res = sqrt(x);
	
	printf("squareRoot of %d = %lf ",x,res);
	return 0;
}
