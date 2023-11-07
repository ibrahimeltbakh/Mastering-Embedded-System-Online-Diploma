#include "linked_list.h"

 struct SStudent* gpFirstStudent = NULL;
void Fill_The_Record(struct SStudent* new_student)
{
    int x;
    float y;

    printf("Enter The ID : ");
    scanf("%d",&x);
    new_student->Student.id = x;

     printf("Enter The Name : ");
     scanf("%s",new_student->Student.name);

     printf("Enter The height : ");
    scanf("%f",&y);
    new_student->Student.height = y;


}

void add_student()
{
    struct SStudent* pLastStudent;
    struct SStudent* pNewStudent;

    //add Student
    //check if the list empty
    if(gpFirstStudent == NULL)
    {
        //create new record
        pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
        gpFirstStudent = pNewStudent;
    }
    else
    {
        //navigate until reach the last node
        pLastStudent = gpFirstStudent;
        while(pLastStudent->PNextStudent)
            pLastStudent = pLastStudent->PNextStudent;

        //create new record
        pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
        pLastStudent->PNextStudent = pNewStudent;

    }
     Fill_The_Record(pNewStudent);
     pNewStudent->PNextStudent = NULL;
}

int delete_student()
{
    struct SStudent* pPreStudent;
    struct SStudent* pCurStudent;
    int id;
    printf("Enter ID To Delete Student : ");
    scanf("%d",&id);

   if(gpFirstStudent)
   {
       pPreStudent= NULL;
       pCurStudent= gpFirstStudent;
       while(pCurStudent)
       {
           if(pCurStudent->Student.id == id)
           {
               if(pPreStudent)
               {
                   pPreStudent->PNextStudent=pCurStudent->PNextStudent;
               }
               else
               {
                   gpFirstStudent = pCurStudent->PNextStudent;
               }
               free(pCurStudent);
               printf("Student Deleted \n");
               return 1;
           }
            pPreStudent=pCurStudent;
            pCurStudent=pCurStudent->PNextStudent;
        }


   }
   printf("Can Not Find This Student :( !!! ");
   return 0;
}
void view_Students()
{
    int count = 0;
    struct SStudent* pCurStudent = gpFirstStudent;
    if(gpFirstStudent == NULL)
        printf("Empty List !!! \n");
    while(pCurStudent)
    {
        printf("RECORD NO.%d \n",count+1);
        printf("Student ID : %d \n",pCurStudent->Student.id);
        printf("Student Name : %s \n",pCurStudent->Student.name);
        printf("Student Highet : %f \n",pCurStudent->Student.height);


        pCurStudent = pCurStudent->PNextStudent;
        count++;
    }
}

void delete_all_students()
{
    struct SStudent* pCurStudent = gpFirstStudent;
    if(gpFirstStudent == NULL)
        printf("Empty List !!! \n");
    while(pCurStudent)
    {
        struct SStudent* pPreStudent = pCurStudent;
        pCurStudent = pCurStudent->PNextStudent;
        free(pPreStudent);
    }
    printf("All Students Deleted \n");
    gpFirstStudent = NULL;
}
void find_n_node( int i)
{
    int count = 0;
    struct SStudent* pCurStudent = gpFirstStudent;
    if(gpFirstStudent == NULL)
        printf("Empty List !!! \n");
    while(pCurStudent)
    {
        if(count == i)
        {
            printf("The Student At this index \n");
            printf("Student ID : %d \n",pCurStudent->Student.id);
            printf("Student Name : %s \n",pCurStudent->Student.name);
            printf("Student Highet : %f \n",pCurStudent->Student.height);

        }
        pCurStudent = pCurStudent->PNextStudent;
        count++;
    }

}
int find_length_iterative()
{
    int count =0;
    struct SStudent* pCurStudent = gpFirstStudent;
    if(gpFirstStudent == NULL)
    {
        printf("Empty List !!! \n");
        return 0;
    }
    while(pCurStudent)
    {
        pCurStudent = pCurStudent->PNextStudent;
        count++;
    }
    return count;
}
int find_length_recursive()
{
   struct SStudent* pCurStudent = gpFirstStudent;
    if(gpFirstStudent == NULL)
    {
        printf("Empty List !!! \n");
        return 0;
    }

    return(find_length_recursive(pCurStudent->PNextStudent));
}
void find_n_node_from_the_end_method_1()
{
   int n, len =  find_length_iterative();
   printf("Enter Student index : ");
    scanf("%d",&n);
   find_n_node(len-n);

}
void find_n_node_from_the_end_method_2()
{
    //init two pointers;
    struct SStudent* pMain = gpFirstStudent;
    struct SStudent* pRef = gpFirstStudent;
    int n , count = 0;
    printf("Enter Student index : ");
    scanf("%d",&n);

    while(n != count)
    {
        pRef = pRef->PNextStudent;
        count++;
    }
    while(pRef)
    {
        pRef = pRef->PNextStudent;
        pMain = pMain->PNextStudent;
    }
    printf("The Student At this index \n");
    printf("Student ID : %d \n",pMain->Student.id);
    printf("Student Name : %s \n",pMain->Student.name);
    printf("Student Highet : %f \n",pMain->Student.height);

}
