#include <stdio.h>
#include <stdlib.h>


int if_prime(int num);
int fact(int num);
void revers();
int pow(int base , int exp);
int main()
{
    //ex1 prime
   /* int x,y ;
    printf("Enter Two Numbers ");
    scanf("%d %d",&x ,&y);
    for (int j = x+1 ; j<y ; j++)
    {
        if(if_prime(j) == 0)
            printf("%d  ",j);

    }*/

    // ex:2 factorial
   /* int x;
    printf("Enter Positive Number ");
    scanf("%d",&x);
    printf("Factorial of %d  =  %d ",x,fact(x));*/

    // ex 3
    /*printf("Enter sentence ");
    revers();*/

    // ex 4
    int x,y,res;

    printf("Enter base number : ");
    scanf("%d",&x);

    printf("Enter power number : ");
    scanf("%d",&y);

    res = pow(x,y);
    printf("%d^%d = %d",x,y,res);

    return 0;
}
int if_prime(int num)
{
    int flag =0 , i;

    for(i = 2 ; i<num/2 ; ++i  )
    {
        if(num % i == 0)
        {
            flag = 1;
            break;

        }

    }
    return flag;
}

int fact(int num)
{

    if(num == 1)
        return 1;
    return num*fact(num-1);
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
int pow(int base , int exp)
{
    if(exp != 0)
    {
        return (base*pow(base , exp-1));

    }
    else
        return 1;

}
