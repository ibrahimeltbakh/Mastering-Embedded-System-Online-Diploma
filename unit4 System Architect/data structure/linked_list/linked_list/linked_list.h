#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


struct Sdata
{
    int id;
    char name[40];
    float height;
};

struct SStudent
{
    struct Sdata Student;
    struct SStudent* PNextStudent;
};

extern struct SStudent* gpFirstStudent;


void Fill_The_Record(struct SStudent* new_student);
void add_student();
int delete_student();
void view_Students();
void delete_all_students();
void find_n_node(int i);
int find_length_iterative();
int find_length_recursive();
void find_n_node_from_the_end_method_1();
void find_n_node_from_the_end_method_2();



#endif // LINKED_LIST_H


