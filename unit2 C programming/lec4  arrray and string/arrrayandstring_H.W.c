#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	/************************H.W1 Array*****************************/
	//EX1:

/*	float m1[2][2] , m2[2][2] , sum[2][2];

	printf("Enter the elements of 1st matrix \r\n");

	for(int i =0 ; i<2 ; i++)
	{
		for(int j =0 ; j< 2 ; j++)
		{
			printf("Enter a%d%d : ",i+1 , j+1  );
			scanf("%f",&m1[i][j]);
		}
	}

	printf("Enter the elements of 2nd matrix \r\n");
	for(int i =0 ; i<2 ; i++)
	{
		for(int j =0 ; j< 2 ; j++)
		{
			printf("Enter b%d%d : ",i+1 , j+1  );
			scanf("%f",&m2[i][j]);

		}
	}
	for(int i =0 ; i<2 ; i++)
	{
		for(int j =0 ; j< 2 ; j++)
		{
            sum[i][j] = m1[i][j] + m2[i][j];
		}
	}
	printf("sum of matrix: ");
	for(int i =0 ; i<2 ; i++)
	{
               printf("\n");
		for(int j =0 ; j< 2 ; j++)
		{

			printf(" %.2f ",sum[i][j]);
		}
	}

*/

    //EX2:
  /*  int n;
    printf("Enter Number Of data ");
    scanf("%d",&n);
    float arr[n] ,sum=0,avr;

    for(int i=0 ; i<n ;i++)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%f",&arr[i]);
    }
    for(int i=0 ; i<n ;i++)
    {
        sum+=arr[i];
    }
    printf("Average = %f ",sum/n);*/


    //  EX3:
  /*  int row,column;
    printf("Enter Rows and column of matrix :");
    scanf("%d %d", &row ,&column);

    int m[row][column] ,m1[column][row];

    printf("Enter elements of matrix \n");
    for(int i =0 ; i<row ; i++)
    {
        for(int j=0 ; j<column ;j++)
        {
            printf("Enter element a%d%d : ",i+1 ,j+1);
            scanf("%d",&m[i][j]);
        }

    }
    printf("Entered Matrix :\n");
    for(int i =0 ; i<row ; i++)
    {
        printf("\n");
        for(int j=0 ; j<column ;j++)
        {
            printf("%d  ",m[i][j]);
        }

    }


     for(int i =0 ; i<row ; i++)
    {
        printf("\n");
        for(int j=0 ; j<column ;j++)
        {
           m1[j][i] = m[i][j];
        }

    }

     printf("Transpose of Matrix :\n");
     for(int i =0 ; i<column ; i++)
    {
        printf("\n");
        for(int j=0 ; j<row ;j++)
        {
            printf("%d  ",m1[i][j]);
        }

    }

*/

 /*   int n ,x,l;
    printf("Enter Number Of data ");
    scanf("%d",&n);
    int arr[n+1];

    for(int i=0 ; i<n ;i++)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter The element to be inserted : ");
    scanf("%d", &x);

    printf("Enter The location : ");
    scanf("%d", &l);

    for(int i = n ; i>=l ; i--)
    {

        arr[i] = arr[i-1];
    }
    arr[l-1] = x;

    for(int i=0 ; i<=n ;i++)
    {
        printf("%d ",arr[i]);
    }

*/

//  EX:5

  /*  int n ,x,l;
    printf("Enter Number Of data ");
    scanf("%d",&n);
    int arr[n];
    l = n+10 ; // location out of the rang
    for(int i=0 ; i<n ;i++)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter The element to be searched : ");
    scanf("%d", &x);

    int i;
    for(i=0 ; i<n ;i++)
    {
        if(x == arr[i])
        {
            l = i;
            break;
        }
    }

    if(l == n+10)
    {
        printf("Number not founded!! \n");
    }
    else
    {

        printf("Number found at the location = %d ",l);
    }

*/

/******************************** STRING H.W *****************************/

//EX:1
 /*   char text[100],x;
    int n=0;
    printf("Enter String : ");
    gets(text);
    printf("Enter Character to find frequency : ");
    scanf("%c",&x);

    int len = strlen(text),i;
    for(i = 0 ; i<= len ; i++)
    {
        if(text[i] == x )
            n++;
    }
    if(n == 0)
    {
        printf("%c not founded ", x);
    }
    else
    {
       printf("frequency of %c = %d ", x,n);
    }
*/
    //EX:2
/*    char text[100];
    int n=0;
    printf("Enter String : ");
    gets(text);

    while(text[n] != '\0' )
    {
        n++;

    }
       printf("Length of string = %d ", n);

*/
    //EX:3

    char text[100];
    printf("Enter String : ");
    gets(text);
    int len = strlen(text),i;
    if(len % 2 != 0)
    {
        for(i=0 ; i<= len/2 ; i++)
        {
        char temp = text[i] ;
        text[i] = text[len-i-1];
        text[len-i-1] = temp;
        }

    }
    else if(len %2 == 0)
    {
        for(i=0 ; i< len/2 ; i++)
        {
        char temp = text[i] ;
        text[i] = text[len-i-1];
        text[len-i-1] = temp;
        }

    }

    printf("Reverse string is :");

    for(i=0 ; i<= len ; i++)
    {
       printf("%c",text[i]);

    }



	return 0;
}
