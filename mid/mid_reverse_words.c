#include<stdio.h>
#include<string.h>


void reverse_words();
int main()
{
	reverse_words();
	
	return 0;
}

void reverse_words()
{
	char text[100],new[100];
    int n=0 ,i,len,j;
    printf("Enter String : ");
    gets(text);
	len = strlen(text);
    while(text[n] != ' ' )
    {
        n++;

    }
	for(int i =0 ; i<n , n<=len ; i++,n++)
	{
		new[i] = text[n+1];
	}
	printf("%s",new);
	printf(" ");
	j=0;
	while(text[j] != ' ' )
    {
		printf("%c",text[j]);
        j++;
    }
      

	
	
}



