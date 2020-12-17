#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/*
    function for date validation

    will take string of date to validate
    return result of validation and display error if invalid
*/
int validateDate(char dateValue[128]);

/*
    function for name validation

    will take string of name to validate
    return result of validation and display error if invalid
*/
int validateName(char nameValue[128]);

/*
    function for student ID validation

    will take string of student ID to validate
    return result of validation and display error if invalid
*/
int validateStID(char idValue[128]);

/*
    control function for date validation

    will take string of date to further sent it to validate function
    return result of validation and value back to called function by pharsing
*/
int dateControl(char valDate[128]);

/*
    control function for name validation

    will take string of name to further sent it to validate function
    return result of validation and value back to called function by pharsing
*/
int nameControl(char valName[128]);

/*
    control function for student ID validation

    will take string of student ID to further sent it to validate function
    return result of validation and value back to called function by pharsing
*/
int stIDControl(char valID[128]);



int validateDate(char dateValue[128])
{
    int result = 0;         /*result of validation*/

    printf("test\n");
    return result;
}

int validateName(char nameValue[128])
{
    int result = 0;         /*result of validation*/


    return result;
}

int validateStID(char idValue[128])
{
    int result = 0;         /*result of validation*/



    return result;
}

int dateControl(char valDate[128])
{
    int date_result = 0;    /*result of validation*/
    char inp_date[128];     /*recieve date from valDate*/
    char date_cpy[128];     /*copy date from valDate to validate*/

    do
    {
        printf("Enter Date to validate (Press * to exit) : ");
        fgets(inp_date,sizeof(inp_date),stdin);
        sscanf(inp_date,"%[^\n]s",date_cpy);
        if (strcmp(date_cpy,"*") == 0)
        {
            date_result = -1;
            printf("\t\tExited Validation\n");
        }
        else
        {
            date_result = validateDate(date_cpy);
            if(date_result == 1)
            {
                strcpy(valDate,date_cpy);
            }
        }
    } while (date_result == 0);
    
    return date_result;
}

int nameControl(char valName[128])
{
    int name_result;        /*result of validation*/

    return name_result;
}

int stIDControl(char valID[128])
{
    int stID_result;        /*result of validation*/

    return stID_result;
}