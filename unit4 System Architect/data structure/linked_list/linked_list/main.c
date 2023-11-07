#include "linked_list.h"

int main()
{
    int n,i;

    while(1)
    {
        printf("========================\n");
        printf(" choose on the following options\n");
        printf(" press 1 to add Student \n");
        printf(" press 2 to delete Student \n");
        printf(" press 3 to view Students \n");
        printf(" press 4 to delete all Students \n");
        printf(" press 5 to find Student using index \n");
        printf(" press 6 to find Students length using iterative \n");
        printf(" press 7 to find Students length using Recursive \n");
        printf(" press 8 to find Student from the end using index(method 1) \n");
        printf(" press 9 to find Student from the end using index(method 2) \n");
        printf(" Enter Option : ");

        scanf("%d",&n);
        printf("\n========================\n");

        switch(n)
        {
        case 1:
            add_student();
            break;
        case 2:
            delete_student();
            break;
        case 3:
            view_Students();
            break;
        case 4:
            delete_all_students();
            break;
        case 5:
            printf("Enter Student index Start From zero ");
            scanf("%d",&i);
            find_n_node(i);
            break;
        case 6:
            printf("Students length = %d",find_length_iterative());
            break;
        case 7:
            printf("Students length = %d",find_length_recursive());
            break;
        case 8:
            find_n_node_from_the_end_method_1();
            break;
        case 9:
            find_n_node_from_the_end_method_2();
            break;

        default:
            printf("Wrong Option !!!");
            break;
        }
    }
    return 0;
}
