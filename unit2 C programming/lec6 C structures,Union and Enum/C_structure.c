#include<stdio.h>
#include<string.h>
struct student{
	char name[50];
	int  age;
	float marks;
}s;
struct distance{
	int   feet;
	float inch;
}d1,d2,sum;
struct complex{
	double m_R;
	double m_I;
};
struct complex read_values(char name[]);
struct complex add_values(struct complex A , struct complex B);
struct complex print_values(char name[] ,struct complex c );

#define pi 3.14
#define area(r) (pi*r*r)

int main()
{
	//ex:1
	/*
	printf("Enter Student Informations\n");
	printf("Enter name : ");
	gets(s.name);
	printf("Enter age : ");
	scanf("%d",&s.age);
	printf("Enter marks : ");
	scanf("%f",&s.marks);
	printf("Student Informations :\nName : %s \nAge : %d \nMarks : %f\n",s.name ,s.age ,s.marks);
	*/
	
	//ex:2
	/*int inch_to_feet =0;
	printf("Enter information of first distance\n");
	printf("Enter Feet : ");
	scanf("%d",&d1.feet);
	printf("Enter inch : ");
	scanf("%f",&d1.inch);
	
	printf("Enter information of second distance\n");
	printf("Enter Feet : ");
	scanf("%d",&d2.feet);
	printf("Enter inch : ");
	scanf("%f",&d2.inch);
	
	sum.feet=d1.feet + d2.feet;
	sum.inch=d1.inch + d2.inch;
	
	if(sum.inch >=12 )
	inch_to_feet = sum.inch/12;
	
	sum.feet += inch_to_feet;
	sum.inch -= (12*inch_to_feet);
	
	printf("sum of distances = %d feet %.3f inch",sum.feet,sum.inch);*/
	
	//ex:3
	/*struct complex x,y,z;
	x = read_values("x");
	y = read_values("y");
	
	z = add_values(x,y);
	
	print_values("z",z);*/
	
	//ex:4
	/*struct student students[3];
	printf("Enter Students Informations\n");
	for(int i =0 ; i<3 ;i++)
	{
		printf("Enter student %d Name : ",i+1);
		scanf("%s",students[i].name);
		printf("Enter student %d Age : ",i+1);
		scanf("%d",&students[i].age);
		printf("Enter student %d Marks : ",i+1);
		scanf("%f",&students[i].marks);
		printf("\n");
	}
	
	printf("Students Informations\n");
	for(int i =0 ; i<3 ;i++)
	{
		printf("Student no.%d \nName : %s \nAge : %d \nMarks : %.2f\n",i+1,students[i].name ,students[i].age ,students[i].marks);
	}*/
	
	//ex:5
	/*int r ;
	printf("Enter Radius ");
	scanf("%d",&r);
	
	float res;
	res = area(r);
	
	printf("Area = %.2f ",res);*/
	
	//ex:6
	
	/*
	size of union = 32 ------> size of char[32] = 32 
	size of structure = 40 ------> 32 for char [32] + 4 for float + 4 for int
	*/
	
	return 0;
}
struct complex read_values(char name[])
{
	struct complex c;
	printf("Enter real and imaginary respectively of %s ",name);
	scanf("%lf %lf",&c.m_R ,&c.m_I);
	return c;
}
struct complex add_values(struct complex A , struct complex B)
{
	struct complex c;
	c.m_R = A.m_R + B.m_R;
	c.m_I = A.m_I + B.m_I;
	
	return c;
}
struct complex print_values(char name[] ,struct complex c )
{
	printf("%s = (%.3lf)+(%.3lf)i\n",name,c.m_R,c.m_I);
}