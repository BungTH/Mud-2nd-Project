#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int choice;             /*recieve choice data*/
    char inp[64];           /*recieve data from users*/

    printf("        Welcome to CPE student Database Manager        \n\n\n");
    printf("*******************************************************\n\n");
    printf("\tHere are available choices : \n");
    printf("\t\t1. Display all records\n");
    printf("\t\t2. Add a new record\n");
    printf("\t\t3. Search and Modify existed record\n");
    printf("\t\t4. Exit Database Manager\n\n");
    printf("*******************************************************\n\n");
    printf("Choose the choice to continue : ");
    fgets(inp,sizeof(inp),stdin);
    sscanf(inp,"%d",&choice);

    while (choice != 4)
    {   
        switch (choice)
        {
            case 1:
                printf("\n\t---Displaying records---\n");
                display();
                printf("All data shown\n\n");
                break;
            case 2:
                printf("\n\t---Adding Data---\n");
                add();
                break;
            case 3:
                printf("\n\t---Modifying Data---\n");
                search();
                break;
            default:
                printf("\t\tNot valid - illegal choice\n\n");
        }
        printf("*******************************************************\n\n");
        printf("\tHere are available choices : \n");
        printf("\t\t1. Display all records\n");
        printf("\t\t2. Add a new record\n");
        printf("\t\t3. Search and Modify existed record\n");
        printf("\t\t4. Exit Database Manager\n\n");
        printf("*******************************************************\n\n");
        printf("Choose the choice to continue : ");
        fgets(inp,sizeof(inp),stdin);
        sscanf(inp,"%d",&choice);
    }
    printf("\n\t\tExited Manager\n");
}