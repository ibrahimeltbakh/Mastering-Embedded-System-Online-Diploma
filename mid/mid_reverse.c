#include<stdio.h>

void revers();


int main()
{
	printf("Enter Digits to reverse : ");
	revers();
	return 0;
}


void revers()
{
    char c;
    scanf("%c",&c);
    if(c != '\n')
    {
        revers();
        printf("%c",c);
    }

}