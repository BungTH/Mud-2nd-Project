#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/*
    function for modify data

    will take pos for position of data found and counter as argument
    return nothing
*/
void modify(int pos[], int counter);

/*
    function for search data

    will take nothing as it's argument
    return nothing
*/
void search();

void search()
{
    FILE *pSample = NULL;       /*position of database file*/
    int i = 0;              /*loop counter*/
    int j = 0;              /*loop counter*/
    int position[30];       /*postion of data found*/
    int choice;             /*recieve choice data*/
    char inp[256];          /*recieve data from file*/
    char datatosearch[256]; /*recieve data to search from inp*/

    pSample = fopen("Sample.txt","r");
    if (pSample == NULL)
    {
        printf("\t\tCan't open database file\n");
    }
    else 
    {
        printf("\t\tSearch option : \n");
        printf("\ttype 1 to search by Student ID\n");
        printf("\ttype 2 to search by Home province code\n");
        printf("\t\tWhich option you want to do : ");
        fgets(inp,sizeof(inp),stdin);
        sscanf(inp,"%d",&choice);
        
        if (choice == 1)
        {
            printf("\n\t\tEnter Student ID address to search : ");
            fgets(inp,sizeof(inp),stdin);
            sscanf(inp,"%[^\n]s",datatosearch);
            pSample = fopen("Sample.txt","r");
            while (fgets(inp,sizeof(inp),pSample) != 0)
            {
                sscanf(inp,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                if (strncmp(datatosearch,textdata.stID,sizeof(datatosearch)) == 0)
                {
                    printf("\tData of Student number %d\n",i+1);
                    printf("------------------------------------------------\n");
                    printf("\tStudent ID : %s\n",textdata.stID);
                    printf("\tName : %s\n",textdata.name);
                    printf("\tDate of birth : %s\n",textdata.date);
                    printf("\tProvince code : %s\n",textdata.home);
                    printf("\tGPA : %s\n",textdata.gpa);
                    printf("\tGender : %s\n",textdata.gender);
                    printf("------------------------------------------------\n\n");
                    position[j] = i;
                    j++;
                }
                i++;
            }
        }

        else if (choice == 2)
        {
            printf("\n\t\tEnter Province code to search : ");
            fgets(inp,sizeof(inp),stdin);
            sscanf(inp,"%[^\n]s",datatosearch);
            pSample = fopen("Sample.txt","r");
            while (fgets(inp,sizeof(inp),pSample) != 0)
            {
                sscanf(inp,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                if (strcmp(datatosearch,textdata.home) == 0)
                {
                    printf("\tData of Student number %d\n",i+1);
                    printf("------------------------------------------------\n");
                    printf("\tStudent ID : %s\n",textdata.stID);
                    printf("\tName : %s\n",textdata.name);
                    printf("\tDate of birth : %s\n",textdata.date);
                    printf("\tProvince code : %s\n",textdata.home);
                    printf("\tGPA : %s\n",textdata.gpa);
                    printf("\tGender : %s\n",textdata.gender);
                    printf("------------------------------------------------\n\n");
                    position[j] = i;
                    j++;
                }
                i++;
            }
        }
        else 
        {
            printf("\t\tNot valid - illegal choice\n\n");
        }
    }
    fclose(pSample);
    modify(position,j);
}

void modify(int pos[], int counter)
{
    FILE *pSample = NULL;       /*position of database file*/
    FILE *pSample_buffer = NULL;/*position of temporary database file*/
    int i = 0;              /*loop counter*/
    int flag = 1;           /*flag to check is user's choice correct*/
    int choice;             /*recieve choice data*/
    int postomodify;        /*position to modify*/
    char inp[256];          /*recieve data from user*/
    char inp_file[256];     /*recieve data from file*/
    char datatochange[256]; /*recieve data to modify from user*/

    if (counter == 0)
    {
        printf("\t---No data found---\n");
    }
    else 
    {
        do
        {
            printf("Which one you want to modify data : ");
            fgets(inp,sizeof(inp),stdin);
            sscanf(inp,"%d",&choice);
            for (i = 0;i < counter;i++)
            {
                if (choice - 1 == pos[i])
                {
                    flag = 1;
                    postomodify = i;
                }
                else
                {
                    flag = 0;
                }
            }
            if (flag == 0)
            {
                printf("\t\tNot valid - illegal choice\n\n");
            }
        } while (flag == 0);
        pSample = fopen("Sample.txt","r");
        pSample_buffer = fopen("Sample_temp.txt","w");
        if (pSample == NULL)
        {
            printf("\t\tCan't open database file\n");
        }
        else 
        {
            i = 0;
            while (fgets(inp_file,sizeof(inp_file),pSample) != 0)
            {
                if (i == postomodify)
                {
                    printf("\t\tYou can modify :\n");
                    printf("\t1. Student ID\n\t2. Name\n\t3. Date of Birth\n\t4. Province code\n\t5. GPA\n\t6. Gender\n\t9. Exit\n\n");
                    do
                    {
                        printf("\t\tWhich data you want to modify : ");
                        fgets(inp,sizeof(inp),stdin);
                        sscanf(inp,"%d",&choice);
                        if (choice == 1)
                        {
                            flag = stIDControl(datatochange);
                            if (flag == 1)
                            {
                                sscanf(inp_file,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                                fprintf(pSample_buffer,"%s*%s*%s*%s*%s*%s",datatochange,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                            }
                        }
                        else if (choice == 2)
                        {
                            flag = nameControl(datatochange);
                            if (flag == 1)
                            {
                                sscanf(inp_file,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                                fprintf(pSample_buffer,"%s*%s*%s*%s*%s*%s",textdata.stID,datatochange,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                            }
                        }
                        else if (choice == 3)
                        {
                            flag = dateControl(datatochange);
                            if (flag == 1)
                            {
                                sscanf(inp_file,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                                fprintf(pSample_buffer,"%s*%s*%s*%s*%s*%s",textdata.stID,textdata.name,datatochange,textdata.home,textdata.gpa,textdata.gender);
                            }
                        }
                        else if (choice == 4)
                        {
                            flag = provinceControl(datatochange);
                            if (flag == 1)
                            {
                                sscanf(inp_file,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                                fprintf(pSample_buffer,"%s*%s*%s*%s*%s*%s",textdata.stID,textdata.name,textdata.date,datatochange,textdata.gpa,textdata.gender);
                            }
                        }
                        else if (choice == 5)
                        {
                            flag = gpaControl(datatochange);
                            if (flag == 1)
                            {
                                sscanf(inp_file,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                                fprintf(pSample_buffer,"%s*%s*%s*%s*%s*%s",textdata.stID,textdata.name,textdata.date,textdata.home,datatochange,textdata.gender);
                            }
                        }
                        else if (choice == 6)
                        {
                            flag = genderControl(datatochange);
                            if (flag == 1)
                            {
                                sscanf(inp_file,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                                fprintf(pSample_buffer,"%s*%s*%s*%s*%s*%s\n",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,datatochange);
                            }
                        }
                        else 
                        {
                            printf("\t\tNot valid - illegal choice\n\n");
                        }
                    } while (choice != 9);
                }
                else 
                {
                    sscanf(inp_file,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                    fprintf(pSample_buffer,"%s*%s*%s*%s*%s*%s\n",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
                }
                i++;
            }
            fclose(pSample);
            fclose(pSample_buffer);
        }
        pSample = fopen("Sample.txt","w");
        pSample_buffer = fopen("Sample_temp.txt","r");
        while (fgets(inp_file,sizeof(inp_file),pSample_buffer) != 0)
        {
            sscanf(inp_file,"%32[^*]*%128[^*]*%32[^*]*%16[^*]*%16[^*]*%2[^*]",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
            printf("------------------------------------------------\n");
            printf("\tStudent ID : %s\n",textdata.stID);
            printf("\tName : %s\n",textdata.name);
            printf("\tDate of birth : %s\n",textdata.date);
            printf("\tProvince code : %s\n",textdata.home);
            printf("\tGPA : %s\n",textdata.gpa);
            printf("\tGender : %s\n",textdata.gender);
            printf("------------------------------------------------\n\n");
            fprintf(pSample,"%s*%s*%s*%s*%s*%s",textdata.stID,textdata.name,textdata.date,textdata.home,textdata.gpa,textdata.gender);
        }
        fclose(pSample);
        fclose(pSample_buffer);
    }
}