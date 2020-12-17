#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int i = 0;                  /*loop counter*/

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

/*
    function for check is there alphabetic character in string

    will take string to check if there're alphabetic character
    return result of checking
*/
int checkAlpha(char checkAl[128]);

/*
    function for check is there number in string

    will take string to check if there're number
    return result of checking
*/
int checkNumber(char checkNum[128]);



int checkAlpha(char checkAl[128])
{
    int result = 0;         /*result of checking*/
    int length;             /*recieve length of input from checkAl*/

    for (i = 0;i < length;i++)
    {
        if(isalpha)
        {
            result = 1;
            break;
        }
        else
        {
            result = 0;
        }
    }

    return result;
}

int checkNumber(char checkNum[128])
{
    int result = 0;         /*result of checking*/
    int length;             /*recieve length of input from checkNum*/

    for (i = 0;i < length;i++)
    {
        if(isdigit)
        {
            result = 1;
            break;
        }
        else
        {
            result = 0;
        }
    }

    return result;
}

int validateDate(char dateValue[128])
{
    int result = 0;         /*result of validation*/
    int length;             /*recieve length of input from dateValue*/
    char day[16];           /*recieve string of day from dateValue*/
    char month[16];         /*recieve string of month from dateValue*/
    char year[16];          /*recieve string of year from dateValue*/
    int day_value;          /*recieve value of day from dateValue*/
    int month_value;        /*recieve value of month from dateValue*/
    int year_value;         /*recieve value of year from dateValue*/

    length = strlen(dateValue);
    if (length == 10)
    {
        if ((dateValue[2] == '/') && (dateValue[5] == '/'))
        {
            sscanf("%[^/]/%[^/]/%[^\n]",day,month,year);
            printf("day : %s\nmonth : %s\nyear : %s",day,month,year);
        }
        else
        {
            printf("\t\tNot valid - wrong format of input (must have /)\n");
        }
    }
    else if (length > 10)
    {
        printf("\t\tNot valid - length is too long\n");
    }
    else if (length < 10)
    {
        printf("\t\tNot valid - length is too short\n");
    }
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