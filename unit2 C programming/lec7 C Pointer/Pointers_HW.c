#include<stdio.h>

struct emp 
{
	char *name;
	int id;
}e;


int main()
{
	//ex:1
	/*
	int m;
	int* ptr = &m;
	*ptr = 29;
	
	printf("Address of m: %x\nValue of m: %d",ptr,*ptr);
	
	int* ab = &m;
	printf("\nAddress of pointer ab: %x\nValue of pointer ab: %d",ab,*ab);
	
	m = 34;
	printf("\nAddress of pointer ab: %x\nValue of pointer ab: %d",ab,*ab);
	
	*ab = 7;
	printf("\nAddress of pointer ab: %x\nValue of pointer ab: %d",ab,*ab);
	*/
	
	//ex:2
	/*char a[27];
	char* p ;
	int i;
	
	p = a;
	
	for(i=0 ; i<26 ; i++)
	{
		*p = i+'A';
		p++;
	}
	
	p = a;
	for(i=0 ; i<26 ; i++)
	{
		printf("%c " ,*p);
		p++;
	}
	*/
	
	//ex:3
	/*
	char s[100];
	char* p;
	p = s;
	printf("Enter String : ");
	gets(s);
	printf("String U Enterd: %s",p);
	while(*p != '\0')
		p++;
	
	printf("\nReversed String :");
	while(p!=s-1)
	{
		printf("%c",*p);
		p--;
	}
	*/
	
	//ex:4
	/*
	int arr[15];
	int* p=arr;
	printf("Enter Array\n");
	for(int i = 0 ; i<5 ; i++)
	{
		printf("Element-%d : ",i+1);
		scanf("%d",p);
		p++;
	}
	p--;
	printf("\n\n");
	for(int i = 4 ; i>=0 ; i--)
	{
		printf("Element-%d : %d\n",i+1,*p);
		p--;
	}
	*/
	
	//ex:5
	struct emp emp1 = {"Ahmed",99} , emp2 = {"Mohamed",101} ,emp3 = {"ibrahem",102};
	struct emp (*arr[]) = {&emp1 ,&emp2 ,&emp3};
	struct emp (*(*p)[3]) = &arr; // p is an array of 3 pointers that return pointers to structure 
	
	printf("Employee Name : %s ",(**(*p+1)).name);
	printf("\nEmployee Id : %d",(*(*p+1))->id);
	return 0;
}