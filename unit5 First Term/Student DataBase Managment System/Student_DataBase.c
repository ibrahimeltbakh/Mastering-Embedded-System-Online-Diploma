/*
*************************************************************
*** @file         :Student_Database.c
*** @auther       :ibrahim samir eltbakh
*** @date         : 30/10/2023
*************************************************************
*/

#include "Student_DataBase.h"

FIFO_Status Student_DataBase_init(Student_t *P_Student ,element_type* buf ,uint32_t length )
{
    // check if buf in memory or not
   if(buf == NULL)
        return FIFO_null;
    P_Student->head = buf;
    P_Student->base = buf;
    P_Student->tail = buf;
    P_Student->count= 0;
    P_Student->length=length;

    return FIFO_no_error;
}
FIFO_Status Add_Student_Manually(Student_t *P_Student)
{
    int id ,course_id;

    // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
    {
        DPRINTF("\n-----------------------------------------------\n");
        DPRINTF("[ERROR] Student_DataBase Is Not Initialized!!!   \n");
        DPRINTF("-------------------------------------------------\n");
        return FIFO_null;

    }
    // check Student_DataBase IS Full OR Not
    if(Student_DataBase_IS_FULL(P_Student) == FIFO_full)
    {
        DPRINTF("\n----------------------------------\n");
        DPRINTF("[Error] Student_DataBase Is FULL !!!\n");
        DPRINTF("------------------------------------\n");
        return FIFO_full;

    }

    DPRINTF("\n------------------------\n");
    DPRINTF("Add The Student Details   \n");
    DPRINTF("--------------------------\n");
    DPRINTF("Enter The Roll Number: ");
    scanf ("%d",&id);

    //check id is taken or not
    while(Student_ID_IS_Taken(P_Student ,id) != 0)
    {
        DPRINTF("\n-------------------------------\n");
        DPRINTF("This Roll Number IS Already Exist\n");
        DPRINTF("---------------------------------\n");
        DPRINTF("Enter New Roll Number: ");
        scanf ("%d",&id);
    }

    P_Student->head->id = id;

    DPRINTF("Enter The First Name of Student: ");
    scanf("%s",P_Student->head->F_name);
    DPRINTF("Enter The Last Name of Student: ");
    scanf("%s",P_Student->head->L_name);
    DPRINTF("Enter The GPA You Obtained: ");
    scanf("%f",&P_Student->head->GPA);
    DPRINTF("Enter The Course Id For each Course: \n");
    for(course_id =0 ; course_id<Max_courses ;course_id++)
    {
        printf("Course %d id: ",course_id+1);
        scanf("%d",&P_Student->head->course_id[course_id]);
    }


    //circler queue
    if(P_Student->head == (P_Student->base + (P_Student->length*sizeof(element_type))))
        P_Student->head = P_Student->base;
    else
        P_Student->head++;

    P_Student->count++;
    DPRINTF("[INFO] Student Details Is Added Successfully \n");
    Find_Total_Number_OF_Students(P_Student);


    return FIFO_no_error;
}
FIFO_Status Add_Student_From_File(Student_t *P_Student)
{
    element_type p_temp;
    char filename[FILE_NAME_SIZE];

    // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
    {
        DPRINTF("\n-----------------------------------------------\n");
        DPRINTF("[ERROR] Student_DataBase Is Not Initialized!!!   \n");
        DPRINTF("-------------------------------------------------\n");
        return FIFO_null;;

    }
    // check Student_DataBase IS Full OR Not
    if(Student_DataBase_IS_FULL(P_Student) == FIFO_full)
    {
        DPRINTF("\n----------------------------------\n");
        DPRINTF("[Error] Student_DataBase Is FULL !!!\n");
        DPRINTF("------------------------------------\n");
        return FIFO_full;

    }

    DPRINTF("Enter File Name: ");
    scanf("%s",filename);

   file = fopen(filename,"r");

    if(file == NULL)
    {
        DPRINTF("-----------------------------------\n");
        DPRINTF("[ERROR] CAN NOT Opening This File. \n");
        DPRINTF("-----------------------------------\n");
    }
    //Loop Till The End OF File
    while(!feof(file))
    {
        fscanf(file,"%d %s %s %f %d %d %d %d %d\n",&p_temp.id,p_temp.F_name,p_temp.L_name ,&p_temp.GPA,
					&p_temp.course_id[0], &p_temp.course_id[1], &p_temp.course_id[2],
					&p_temp.course_id[3], &p_temp.course_id[4]);
        //check IF ID Taken Or Not
        if(!Student_ID_IS_Taken(P_Student ,p_temp.id))
        {
            strcpy(P_Student->head->F_name,p_temp.F_name);
            strcpy(P_Student->head->L_name,p_temp.L_name);
            P_Student->head->id = p_temp.id;
            P_Student->head->GPA = p_temp.GPA;
            for(int i = 0 ; i<Max_courses ;i++)
            {
                P_Student->head->course_id[i] = p_temp.course_id[i];
            }
            P_Student->count++;
            if(P_Student->head == (P_Student->base + (P_Student->length*sizeof(element_type))))
            {
                P_Student->head = P_Student->base;
            }
            else{
                P_Student->head++;
            }

            DPRINTF("[info] Roll Number %d Saved Successfully \n",p_temp.id);

        }
        else{
            DPRINTF("\n-----------------------------------------\n");
            DPRINTF("[ERROR] This Roll Number %d IS Already Exist\n",p_temp.id);
            DPRINTF("-------------------------------------------\n");
        }
    }

    DPRINTF("----------------------------------------------\n");
    DPRINTF("[info] Students Details Is Added Successfully \n");
    DPRINTF("----------------------------------------------\n");

   return FIFO_no_error;
}
FIFO_Status Find_Student_By_Roll_Number(Student_t *P_Student)
{
    element_type *P_temp = P_Student->tail;
    int RollNumber,i=0,flag=0;

    // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
    {
        DPRINTF("\n-----------------------------------------------\n");
        DPRINTF("[ERROR] Student_DataBase Is Not Initialized!!!   \n");
        DPRINTF("-------------------------------------------------\n");
        return  FIFO_null;

    }
    // check Student_DataBase IS Empty OR Not
    if(Student_DataBase_IS_empty(P_Student) == FIFO_empty)
    {
        DPRINTF("\n-----------------------------------\n");
        DPRINTF("[Error] Student_DataBase Is Empty !!!\n");
        DPRINTF("-------------------------------------\n");
        return  FIFO_empty;

    }

    DPRINTF("--------------------------------\n");
    DPRINTF("Enter The Roll Number Of Student: ");
    scanf("%d",&RollNumber);
    for(;i<P_Student->count;i++)
    {
        if(P_temp->id == RollNumber)
        {
            Print_Student_Informations(P_temp,Roll_Number_F);
            flag=1;
            break;
        }
        if(P_temp == (P_Student->base + (P_Student->length*sizeof(element_type))))
        {
            P_temp = P_Student->base;
        }
        else{
            P_temp++;
        }
    }
    if(!flag)
    {
        DPRINTF("\n---------------------------------------------\n");
        DPRINTF("[ERROR] Roll Number %d Not Found !!!\n",RollNumber);
        DPRINTF("\n---------------------------------------------\n");
    }

    return FIFO_no_error;
}

FIFO_Status Find_Student_By_First_name(Student_t *P_Student)
{
    element_type *P_temp = P_Student->tail;
    char name[50];
    int i=0,flag=0;

    // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
    {
        DPRINTF("\n-----------------------------------------------\n");
        DPRINTF("[ERROR] Student_DataBase Is Not Initialized!!!   \n");
        DPRINTF("-------------------------------------------------\n");
        return;

    }
    // check Student_DataBase IS Empty OR Not
    if(Student_DataBase_IS_empty(P_Student) == FIFO_empty)
    {
        DPRINTF("\n-----------------------------------\n");
        DPRINTF("[Error] Student_DataBase Is Empty !!!\n");
        DPRINTF("-------------------------------------\n");
        return;

    }

    DPRINTF("-------------------------------\n");
    DPRINTF("Enter The First Name Of Student: ");
    scanf("%s",name);

    for(;i<P_Student->count;i++)
    {
        if(!strcmp(P_temp->F_name,name))
        {
            Print_Student_Informations(P_temp,First_Name_F);
            flag =1;
        }
        if(P_temp == (P_Student->base + (P_Student->length*sizeof(element_type))))
        {
            P_temp = P_Student->base;
        }
        else{
            P_temp++;
        }
    }
    if(!flag)
    {
        DPRINTF("\n---------------------- ---------\n");
        DPRINTF("[ERROR] This Name IS Not Found !!!\n");
        DPRINTF("\n---------------------- ---------\n");
    }

    return FIFO_no_error;
}

FIFO_Status Find_Students_Regesteres_AT_TheCourse(Student_t *P_Student)
{
    element_type *P_temp = P_Student->tail;
    int CourseID,i=0,j=0,flag=0;

    // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
    {
        DPRINTF("\n-----------------------------------------------\n");
        DPRINTF("[ERROR] Student_DataBase Is Not Initialized!!!   \n");
        DPRINTF("-------------------------------------------------\n");
        return;

    }
    // check Student_DataBase IS Empty OR Not
    if(Student_DataBase_IS_empty(P_Student) == FIFO_empty)
    {
        DPRINTF("\n-----------------------------------\n");
        DPRINTF("[Error] Student_DataBase Is Empty !!!\n");
        DPRINTF("-------------------------------------\n");
        return;

    }

    DPRINTF("--------------------------------\n");
    DPRINTF("Enter The Course ID: ");
    scanf("%d",&CourseID);
    for(;i<P_Student->count;i++)
    {
        for(j=0;j<Max_courses;j++)
        {
            if(P_temp->course_id[j] == CourseID)
            {
                Print_Student_Informations(P_temp,Course_ID_F);
                flag=1;
            }
        }
        if(P_temp == (P_Student->base + (P_Student->length*sizeof(element_type))))
        {
            P_temp = P_Student->base;
        }
        else{
            P_temp++;
        }
    }
    if(!flag)
    {
        DPRINTF("\n---------------------- ----------------------\n");
        DPRINTF("[ERROR] Roll Number %d Not Found !!!\n",CourseID);
        DPRINTF("\n---------------------- ----------------------\n");
    }

    return FIFO_no_error;

}
FIFO_Status Find_Total_Number_OF_Students(Student_t *P_Student)
{
    // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
    {
        DPRINTF("\n-----------------------------------------------\n");
        DPRINTF("[ERROR] Student_DataBase Is Not Initialized!!!   \n");
        DPRINTF("-------------------------------------------------\n");
        return;

    }
    // check Student_DataBase IS Empty OR Not
    if(Student_DataBase_IS_empty(P_Student) == FIFO_empty)
    {
        DPRINTF("\n-----------------------------------\n");
        DPRINTF("[Error] Student_DataBase Is Empty !!!\n");
        DPRINTF("-------------------------------------\n");
    }

    DPRINTF("---------------------------------------\n");
    DPRINTF("[INFO] The Total Number Of Student is %d \n",P_Student->count);
    DPRINTF("[INFO] You can Add Up To %d Students \n",Max_Students);
    DPRINTF("[INFO] You can Add %d More Students \n",(Max_Students-P_Student->count));
    DPRINTF("---------------------------------------\n");

    return FIFO_no_error;
}
FIFO_Status Delete_Student_By_Roll_Number(Student_t *P_Student)
{
    element_type *P_temp = P_Student->tail;
    int RollNumber,i=0,flag=0;

    // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
    {
        DPRINTF("\n-----------------------------------------------\n");
        DPRINTF("[ERROR] Student_DataBase Is Not Initialized!!!   \n");
        DPRINTF("-------------------------------------------------\n");
        return;

    }
    // check Student_DataBase IS Empty OR Not
    if(Student_DataBase_IS_empty(P_Student) == FIFO_empty)
    {
        DPRINTF("\n-----------------------------------\n");
        DPRINTF("[Error] Student_DataBase Is Empty !!!\n");
        DPRINTF("-------------------------------------\n");
        return;

    }

    DPRINTF("----------------------------------------------\n");
    DPRINTF("Enter The Roll Number Which You Want To delete: ");
    scanf("%d",&RollNumber);
    for(;i<P_Student->count;i++)
    {
        if(P_temp->id == RollNumber)
        {
            *(P_temp) = *(P_Student->tail);
            DPRINTF("----------------------------------------------\n");
            DPRINTF("[INFO] The Roll Number Is Removed Successfully\n");
            DPRINTF("----------------------------------------------\n");
            P_Student->count--;
            Find_Total_Number_OF_Students(P_Student);
            flag=1;
            break;
        }
        if(P_temp == (P_Student->base + (P_Student->length*sizeof(element_type))))
        {
            P_temp = P_Student->base;
        }
        else{
            P_temp++;
        }
    }
    if(!flag)
    {
        DPRINTF("\n---------------------- ----------------------\n");
        DPRINTF("[ERROR] Roll Number %d Not Found !!!\n",RollNumber);
        DPRINTF("\n---------------------- ----------------------\n");
    }

    return FIFO_no_error;
}
FIFO_Status Update_Student_By_Roll_Number(Student_t *P_Student)
{
    element_type *P_temp = P_Student->tail;
    int RollNumber,choice,id,course_id,i=0,flag=0;

    // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
    {
        DPRINTF("\n-----------------------------------------------\n");
        DPRINTF("[ERROR] Student_DataBase Is Not Initialized!!!   \n");
        DPRINTF("-------------------------------------------------\n");
        return;

    }
    // check Student_DataBase IS Empty OR Not
    if(Student_DataBase_IS_empty(P_Student) == FIFO_empty)
    {
        DPRINTF("\n-----------------------------------\n");
        DPRINTF("[Error] Student_DataBase Is Empty !!!\n");
        DPRINTF("-------------------------------------\n");
        return;

    }

    DPRINTF("--------------------------------\n");
    DPRINTF("Enter The Roll Number To update the Entry: ");
    scanf("%d",&RollNumber);
    for(;i<P_Student->count;i++)
    {
        if(P_temp->id == RollNumber)
        {
            DPRINTF("Enter Which Record DO You Want To Update \n1. First Name\n2. LastName\n3. Roll Number\n4. GPA\n5.Courses\nYour Choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                DPRINTF("Enter The First Name of Student: ");
                scanf("%s",P_temp->F_name);
                break;
            case 2:
                DPRINTF("Enter The Last Name of Student: ");
                scanf("%s",P_temp->L_name);
                break;
            case 3:
                DPRINTF("Enter Roll Number of Student:");
                scanf ("%d",&id);
                //check id is taken or not
                while(Student_ID_IS_Taken(P_temp ,id) != 0)
                {
                    DPRINTF("\n-------------------------------\n");
                    DPRINTF("This Roll Number IS Already Exist\n");
                    DPRINTF("---------------------------------\n");
                    DPRINTF("Enter New Roll Number: ");
                    scanf ("%d",&id);
                }

                P_temp->id = id;
                break;
            case 4:
                DPRINTF("Enter The GPA You Obtained: ");
                scanf("%f",&P_temp->GPA);
                break;
            case 5:
                DPRINTF("Enter The Course Id For each Course: \n");
                for(course_id =0 ; course_id<Max_courses ;course_id++)
                {
                    DPRINTF("Course %d id: ",course_id+1);
                    scanf("%d",&P_temp->course_id[course_id]);
                }
                break;
            default:
                 DPRINTF("Wrong Choice !!! ");

            }
            DPRINTF("---------------------------------------\n");
            DPRINTF("[INFO] The Student Updated Successfully\n");
            DPRINTF("---------------------------------------\n");
            flag = 1;
            break;
        }
        if(P_temp == (P_Student->base + (P_Student->length*sizeof(element_type))))
        {
            P_temp = P_Student->base;
        }
        else{
            P_temp++;
        }
    }
    if(!flag)
    {
        DPRINTF("\n---------------------------------------------\n");
        DPRINTF("[ERROR] Roll Number %d Not Found !!!\n",RollNumber);
        DPRINTF("\n---------------------------------------------\n");
    }

    return FIFO_no_error;
}
FIFO_Status Student_DataBase_IS_FULL(Student_t *P_Student)
{
     // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
        return FIFO_null;
    //check Student_DataBase Full
    if(P_Student->count == Max_Students)
    {
        return FIFO_full;
    }
    return FIFO_no_error;
}
FIFO_Status Student_DataBase_IS_empty(Student_t *P_Student)
{
    // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
        return FIFO_null;
    //check Student_DataBase empty
    if(P_Student->count == 0)
    {
        return FIFO_empty;
    }
    return FIFO_no_error;

}
int Student_ID_IS_Taken(Student_t *P_Student,int id)
{
    element_type *p_Temp = P_Student->tail;
    int i;

    for(i = 0 ;i< P_Student->count ; i++)
    {
        if(p_Temp->id == id )
           return 1;
        p_Temp++;
    }
    return 0;

}
void Print_Student_Informations(element_type *P_temp,int which_function)
{
    int n,j;
    DPRINTF("\n----------------------\n");
    DPRINTF("The Student Details are \n");

    switch(which_function)
    {
    case 1:
            n=0;
            DPRINTF("The First Name Is: ");
            while(P_temp->F_name[n] != '\0')
            {
                DPRINTF("%c",P_temp->F_name[n]);
                n++;
            }
            DPRINTF("\n");
            n=0;
            DPRINTF("The Last Name Is: ");
            while(P_temp->L_name[n] != '\0')
            {
                DPRINTF("%c",P_temp->L_name[n]);
                n++;
            }
            DPRINTF("\n");
            DPRINTF("The GPA Is %0.2f: \n",P_temp->GPA);
            DPRINTF("The ID For Each Course \n");
            for (j = 0;j<Max_courses;j++)
                printf("Course ID Number: %d\n",P_temp->course_id[j]);
            break;
    case 2:
            n=0;
            DPRINTF("The First Name Is: ");
            while(P_temp->F_name[n] != '\0')
            {
                DPRINTF("%c",P_temp->F_name[n]);
                n++;
            }
            DPRINTF("\n");
            n=0;
            DPRINTF("The Last Name Is: ");
            while(P_temp->L_name[n] != '\0')
            {
                DPRINTF("%c",P_temp->L_name[n]);
                n++;
            }
            DPRINTF("\n");
            DPRINTF("The Roll Number is: %d \n",P_temp->id);
            DPRINTF("The GPA Is: %0.2f \n",P_temp->GPA);
            DPRINTF("The ID For Each Course \n");
            for (j = 0;j<Max_courses;j++)
                printf("Course ID Number: %d\n",P_temp->course_id[j]);
            break;
    case 3:
            n=0;
            DPRINTF("The First Name Is: ");
            while(P_temp->F_name[n] != '\0')
            {
                printf("%c",P_temp->F_name[n]);
                n++;
            }
            DPRINTF("\n");
            n=0;
            DPRINTF("The Last Name Is: ");
            while(P_temp->L_name[n] != '\0')
            {
                DPRINTF("%c",P_temp->L_name[n]);
                n++;
            }
            DPRINTF("\n");
            DPRINTF("The Roll Number is: %d \n",P_temp->id);
            DPRINTF("The GPA Is: %0.2f \n",P_temp->GPA);
            break;
    }

    DPRINTF("\n----------------------\n");
    return FIFO_no_error;
}
void Print_All_Students_Informations(Student_t *P_Student)
{
    element_type *P_temp = P_Student->tail;
    int i=0,n=0,j;
    // check Student_DataBase Valid
    if(!P_Student->head || !P_Student->base || !P_Student->tail)
    {
        DPRINTF("\n-----------------------------------------------\n");
        DPRINTF("[ERROR] Student_DataBase Is Not Initialized!!!   \n");
        DPRINTF("-------------------------------------------------\n");
        return;

    }
    // check Student_DataBase IS Empty OR Not
    if(Student_DataBase_IS_empty(P_Student) == FIFO_empty)
    {
        DPRINTF("\n-----------------------------------\n");
        DPRINTF("[Error] Student_DataBase Is Empty !!!\n");
        DPRINTF("-------------------------------------\n");
        return;
    }
    for(; i<P_Student->count;i++)
    {
        DPRINTF("-------------------------------------\n");
        n=0;
        DPRINTF("The First Name Is: ");
        while(P_temp->F_name[n] != '\0')
        {
            DPRINTF("%c",P_temp->F_name[n]);
            n++;
        }
        DPRINTF("\n");
        n=0;
        DPRINTF("The Last Name Is: ");
        while(P_temp->L_name[n] != '\0')
        {
            DPRINTF("%c",P_temp->L_name[n]);
            n++;
        }
        DPRINTF("\n");
        DPRINTF("The Roll Number is: %d \n",P_temp->id);
        DPRINTF("The GPA Is: %0.2f \n",P_temp->GPA);
        DPRINTF("The ID For Each Course \n");
        for (j=0;j<Max_courses;j++)
            printf("Course ID Number: %d\n",P_temp->course_id[j]);
        DPRINTF("-------------------------------------\n");

       if(P_temp == (P_Student->base + (P_Student->length*sizeof(element_type))))
        {
            P_temp = P_Student->base;
        }
        else{
            P_temp++;
        }
    }
    return FIFO_no_error;
}
void EXIT()
{
    DPRINTF("---------------------------------------------------\n");
    DPRINTF("THANK YOU FOR YOUR TIME SEE YOU LATER GOOD BYE :)  \n");
    DPRINTF("---------------------------------------------------\n");
    exit(0);
}
