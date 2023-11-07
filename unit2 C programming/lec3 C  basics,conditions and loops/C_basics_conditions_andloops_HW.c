/*
 * main.c
 *
 *  Created on: May 13, 2023
 *      Author: eltba
 */

#include"stdio.h"

int main()
{
	/****************** H.W 1 ********************/
	//ex:5
	/*	char x;
	printf("Enter A Character");
	fflush(stdout);
	scanf("%c" , &x);

	printf("ASCII Value of %c = %d\n",x,x);
	 */

	//ex:6
	/*  int a,b,temp;
	printf("Enter value of a ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d" , &a);
	printf("Enter value of b ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d" , &b);

	temp = a;
	a    = b;
	b    = temp;
	printf("After swapping, value of a = %d \nAfter swapping, value of b = %d\n",a,b);
	 */
	/****************** H.W 2 ********************/

	//EX:1
	/*int a;
	printf("Enter value ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d" , &a);

	if(a%2 == 0)
		printf("%d is even",a);
	else
		printf("%d is odd",a);
	 */
	//EX:2
	/*char a;
	printf("Enter an alphabet ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c" , &a);
	if(a == 'a' || a == 'e' || a=='i' || a=='o' || a=='u')
			printf("%c is a vowel",a);
		else
			printf("%c is consonant",a);*/

	//ex:5
	/*char a;
	printf("Enter Character");
	fflush(stdout);
	fflush(stdin);
	scanf("%c" , &a);
	if(a >= 'a' && a<='z' || a >= 'A' && a<='Z')
		printf("%c is an alphabet",a);
	else
		printf("%c is not alphabet",a);*/

	//ex:6

	/*int a,sum=0,i=1;
	printf("Enter value ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d" , &a);

	while(i<=a)
	{
		sum+=i;
		i++;
	}
	printf("sum = %d \n",sum);*/

	//ex:7
	/*int a, fact =1 , i=1;
	printf("Enter value ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d" , &a);
	if(a < 0)
	{
		printf("Error !!! Factorial of negative number does not exist \n");
		return 0;
	}
	else if( a== 0 ||a== 1)
	{
		printf("Factorial = 1\r\n");
		return 0;
	}
	else
	{
		while(a>i)
		{
			fact *=a;
			a--;
		}
	}
	printf("Factorial = %d \n",fact);*/


	return 0;
}
