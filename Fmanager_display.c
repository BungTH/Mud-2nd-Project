#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/*
    function for display data

    will take nothing as it's argument
    return nothing
*/
void display();

void display()
{
    FILE *pSample = NULL;       /*position of database file*/
    int i = 0;              /*loop counter*/
    char inp[256];          /*recieve data from file*/

    pSample = fopen("Sample.txt","r");
    if (pSample == NULL)
    {
        printf("\t\tCan't open database file\n");
    }
    else 
    {
        while (fgets(inp,sizeof(inp),pSample) != 0)
        {
            sscanf(inp,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
            printf("\tData of Student number %d\n",i+1);
            printf("------------------------------------------------\n");
            printf("\tStudent ID : %s\n",textdata.stID);
            printf("\tName : %s\n",textdata.name);
            printf("\tDate of birth : %s\n",textdata.date);
            printf("\tProvince code : %s\n",textdata.home);
            printf("\tGPA : %s\n",textdata.gpa);
            printf("\tGender : %s\n",textdata.gender);
            printf("------------------------------------------------\n\n");
            i++;
        }
    }
    fclose(pSample);
}