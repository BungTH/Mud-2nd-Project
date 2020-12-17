#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/*
    function for adding data

    will take nothing as it's argument
    return nothing
*/
void add();

void add()
{
    FILE *pSample = NULL;       /*position of database file*/
    int i = 0;              /*loop counter*/
    int flag = 0;           /*checker for each validation*/
    char inp[256];          /*recieve data from file*/

    flag = stIDControl(textdata.stID);
    if (flag == 1)
    {
        flag = nameControl(textdata.name);
        if (flag == 1)
        {
            flag = dateControl(textdata.date);
            if (flag == 1)
            {
                flag = provinceControl(textdata.home);
                if (flag == 1)
                {
                    flag = gpaControl(textdata.gpa);
                    if (flag == 1)
                    {
                        flag = genderControl(textdata.gender);
                        if (flag == 1)
                        {
                            pSample = fopen("Sample.txt","a");
                            fprintf(pSample,"%s*%s*%s*%s*%s*%s\n",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                            printf("\t\tWriting Data Complete\n\n");
                            fclose(pSample);
                        }
                        else
                        {
                            printf("\t\tExited validation\n");
                            printf("\t\tAdding process cancelled\n\n");
                        }
                    }
                    else 
                    {
                        printf("\t\tExited validation\n");
                        printf("\t\tAdding process cancelled\n\n");
                    }
                }
                else 
                {
                    printf("\t\tExited validation\n");
                    printf("\t\tAdding process cancelled\n\n");
                }
            }
            else 
            {
                printf("\t\tExited validation\n");
                printf("\t\tAdding process cancelled\n\n");
            }
        }
        else 
        {
            printf("\t\tExited validation\n");
            printf("\t\tAdding process cancelled\n\n");
        }
    }
    else
    {
        printf("\t\tExited validation\n");
        printf("\t\tAdding process cancelled\n\n");
    }
}