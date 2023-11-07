/*
*************************************************************
*** @file         :main.c
*** @auther       :ibrahim samir eltbakh
*** @date         : 30/10/2023
*************************************************************
*/



#include "Student_DataBase.h"

element_type info[Max_Students];
int main()
{

    int choice ;
    Student_t Student;
    if(Student_DataBase_init(&Student,&info,50)== FIFO_no_error);
        DPRINTF("Initialization Done Successfully \n");

    DPRINTF("Welcome To The Student Managment System\n");
    while(1)
    {
        DPRINTF("1. Add The Student Details Manually\n");
        DPRINTF("2. Add The Student Details From Text File\n");
        DPRINTF("3. Find The Student Details By Roll Number\n");
        DPRINTF("4. Find The Student Details By First Name\n");
        DPRINTF("5. Find The Student Details By The Course ID\n");
        DPRINTF("6. Find The Total Number Of Students\n");
        DPRINTF("7. Delete The Student Details By Roll Number\n");
        DPRINTF("8. Update The Student Details By Roll Number\n");
        DPRINTF("9. Show All Informations\n");
        DPRINTF("10. To Exit\n");
        DPRINTF("Enter Your Choice To Perform The Task: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            Add_Student_Manually(&Student);
            break;
        case 2:
            Add_Student_From_File(&Student);
            break;
        case 3:
            Find_Student_By_Roll_Number(&Student);
            break;
        case 4:
            Find_Student_By_First_name(&Student);
            break;
        case 5:
            Find_Students_Regesteres_AT_TheCourse(&Student);
            break;
        case 6:
            Find_Total_Number_OF_Students(&Student);
            break;
        case 7:
            Delete_Student_By_Roll_Number(&Student);
            break;
        case 8:
            Update_Student_By_Roll_Number(&Student);
            break;
        case 9:
            Print_All_Students_Informations(&Student);
            break;
        case 10:
            EXIT();
            break;

        default:
            DPRINTF("Wrong Choice !!! ");
            DPRINTF("Enter New Choice To Perform The Task:\n");
        }
    }

    return 0;
}
