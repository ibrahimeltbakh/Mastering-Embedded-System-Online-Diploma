#include<stdio.h>

int unique(int *a,int len);
int main()
{
	int a[] = {4,2,4},len;
	len = sizeof(a) / sizeof(a[0]);
	printf("res = %d",unique(a,len));
	
	
}

int unique(int *a,int len)
{
	int i,flag =0,res;
	for(i=0 ; i<len ; i++)
	{
		for(int j = i+1 ; j<len ; j++)
		{
			if(a[i] == a[j])
				break;
			res = a[i];
		}
		
	}
	return res;
}