/*
*************************************************************
*** @file         :Student_Database.h
*** @auther       :ibrahim samir eltbakh
*** @date         : 30/10/2023
*************************************************************
*/

#ifndef STUDENT_DATABASE_H_
#define STUDENT_DATABASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <conio.h>


#define Max_Students 50
#define Max_courses  5

/*
*****************************************************************
*** define fixed Numbers To Pass It To (Show_Student_INformation)
*** Function to print different Details for each function
*****************************************************************
*/
#define Roll_Number_F   1
#define First_Name_F    2
#define Course_ID_F     3


/*
*****************************************************************
*** define FILE_NAME_SIZE for file name we will use
*****************************************************************
*/
#define FILE_NAME_SIZE    1024


FILE *file;


typedef struct{
    char F_name[50];
    char L_name[50];
    int id;
    float GPA;
    int course_id[Max_courses];
}Student_info;

#define element_type          Student_info

typedef struct{

    uint32_t length;
    uint32_t count;
    element_type *head;
    element_type *base;
    element_type *tail;

}Student_t;

typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
}FIFO_Status;


FIFO_Status Student_DataBase_init(Student_t *P_Student ,element_type* buf ,uint32_t length );
FIFO_Status Add_Student_Manually(Student_t *P_Student);
FIFO_Status Add_Student_From_File(Student_t *P_Student);
FIFO_Status Find_Student_By_Roll_Number(Student_t *P_Student);
FIFO_Status Find_Student_By_First_name(Student_t *P_Student);
FIFO_Status Find_Students_Regesteres_AT_TheCourse(Student_t *P_Student);
FIFO_Status Delete_Student_By_Roll_Number(Student_t *P_Student);
FIFO_Status Find_Total_Number_OF_Students(Student_t *P_Student);
FIFO_Status Update_Student_By_Roll_Number(Student_t *P_Student);
FIFO_Status Student_DataBase_IS_FULL(Student_t *P_Student);
FIFO_Status Student_DataBase_IS_empty(Student_t *P_Student);
int Student_ID_IS_Taken(Student_t *P_Student,int id);
void Print_Student_Informations(element_type *P_temp,int which_function);
void Print_All_Students_Informations(Student_t *P_Student);
void EXIT();


#define DPRINTF(...)	fflush(stdin);\
						fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);\
						fflush(stdout);


#endif

