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
    int check = 0;          /*result of checking*/
    int length;             /*recieve length of input from checkAl*/

    length = strlen(checkAl);
    for (i = 0;i < length;i++)
    {
        if (isalpha(checkAl))
        {
            check = 1;
            break;
        }
        else if (checkAl[i] == '/')
        {
            if ((i = 2) || (i == 5))
            {
                continue;
            }
            else
            {
                check = -1;
                break;
            }
        }
        
        else
        {
            check = 0;
        }
    }

    return check;
}

int checkNumber(char checkNum[128])
{
    int check = 0;          /*result of checking*/
    int length;             /*recieve length of input from checkNum*/

    length = strlen(checkNum);
    for (i = 0;i < length;i++)
    {
        if (isdigit(checkNum))
        {
            check = 1;
            break;
        }
        else if (checkNum[i] == '/')
        {
            if ((i = 2) || (i == 5))
            {
                continue;
            }
            else
            {
                check = -1;
                break;
            }
        }
        else
        {
            check = 0;
        }
    }

    return check;
}

int validateDate(char dateValue[128])
{
    int result = 0;         /*result of validation*/
    int alpha_check = 0;    /*result of checkAlpha*/
    int length;             /*recieve length of input from dateValue*/
    int day;                /*recieve value of day from dateValue*/
    int month;              /*recieve value of month from dateValue*/
    int year;               /*recieve value of year from dateValue*/

    length = strlen(dateValue);
    if (length == 10)
    {
        if ((dateValue[2] == '/') && (dateValue[5] == '/'))
        {
            if (isdigit(dateValue[0]) && isdigit(dateValue[1]) && isdigit(dateValue[3]) && isdigit(dateValue[4]) && isdigit(dateValue[6]) && isdigit(dateValue[7]) && isdigit(dateValue[8]) && isdigit(dateValue[9]))
            {
                sscanf(dateValue,"%d/%d/%d",&day,&month,&year);
                if ((year <= 2563) && (year >= 2463))
                {
                    if ((month <= 12) && (month >= 1))
                    {
                        if ((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                        {
                            printf("\t\tValid Data\n");
                            result = 1;
                        }
                        else if ((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11))
                        {
                            printf("\t\tValid Data\n");
                            result = 1;
                        }
                        else if ((day>=1 && day<=28) && (month==2))
                        {
                            printf("\t\tValid Data\n");
                            result = 1;
                        }
                        else if (day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0)))
                        {
                            printf("\t\tValid Data\n");
                            result = 1;
                        }
                        else
                        {
                            printf("\t\tNot valid - day is illegal\n");
                            result = 0;
                        }
                    }
                    else 
                    {
                        printf("\t\tNot valid - month is illegal\n");
                        result = 0;
                    }
                }
                else if (year > 2563)
                {
                    printf("\t\tNot vlaid - year can't be in future\n");
                    result = 0;
                }
                else 
                {
                    printf("\t\tNot valid - year is outside allowed range\n");
                    result = 0;
                }
            }
            else
            {
                printf("\t\tNot valid - alphabetic character is prohibited\n");
                result = 0;
            }
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