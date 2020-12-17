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
    int i = 0;              /*loop counter*/
    int title_check = 0;    /*result of title check*/
    int length;             /*recieve length of input from dateValue*/
    int first_length;       /*recieve length of input from first name*/
    int last_length;        /*recieve length of input from last name*/
    int space_count = 0;    /*count number of spacebar*/
    char title[16];         /*recieve title from nameValue*/
    char first_name[64];    /*recieve first name from nameValue*/
    char last_name[64];     /*recieve last name from nameValue*/
    const char *title_format[4] = {"Mr.","Ms.","Miss","Mrs."};
                            /*format for name title*/

    length = strlen(nameValue);

    for (i = 0;i < length;i++)
    {
        if (nameValue[i] == ' ')
        {
            space_count++;
        }
    }
    if (space_count == 2)
    {
        sscanf(nameValue,"%s %s %s",title,first_name,last_name);
        for (i = 0; i < 4;i++)
        {
            if (strcasecmp(title,title_format[i]) == 0)
            {
                title_check = 1;
                break;
            }
            else 
            {
                title_check = 0;
            }
        }
        if (title_check == 1)
        {
            first_length = strlen(first_name);
            last_length = strlen(last_name);
            if ((first_length <= 30) && (first_length >= 2))
            {
                if ((last_length <= 30) && (last_length >= 2))
                {
                    printf("\t\tValid Data\n");
                    result = 1;
                }
                else 
                {
                    printf("\t\tNot valid - last name must be at least 2 length long and no more than 30 length long\n");
                    result = 0;
                }
            }
            else
            {
                printf("\t\tNot valid - first name must be at least 2 length long and no more than 30 length long\n");
                result = 0;
            }
        }
        else 
        {
            printf("\t\tNot valid - No title or Other title is prohibited\n");
            result = 0;
        }
    }
    else
    {
        printf("\t\tNot valid - there must be 2 spacebar\n");
        result = 0;
    }

    return result;
}

int validateStID(char idValue[128])
{
    int result = 0;         /*result of validation*/
    int i = 0;              /*loop counter*/
    int digit_check = 1;    /*result of digit check*/    
    int length;             /*recieve length of input from idValue*/
    long int stID_value;    /*recieve student ID from idValue*/   
    int yy;                 /*recieve yy value from idValue*/
    int middle;             /*recieve middle code form idValue*/        
    int pp;                 /*recieve pp value from idValue*/
    int dd;                 /*recieve dd value from idValue*/

    length = strlen(idValue);
    if (length == 11)
    {
        for (i = 0;i < length;i++)
        {
            if (isdigit(idValue[i]))
            {
                digit_check = 1;
            }
            else 
            {
                digit_check = 0;
                break;
            }
        }
        if (digit_check == 1)
        {
            sscanf(idValue,"%ld",&stID_value);
            yy = stID_value / 1000000000;
            middle = (stID_value / 10000) % 100000;
            pp = (stID_value / 100) % 100;
            dd = stID_value % 100;
            if (middle == 7050)
            {
                if ((yy <= 63) && (yy >= 55))
                {
                    if ((pp == 34) || (pp == 10))
                    {
                        if (dd == 0)
                        {
                            printf("\t\tNot valid - last two digits can't be 0s\n");
                            result = 0;
                        }
                        else
                        {
                            printf("\t\tValid Data\n");
                            result = 1;
                        }
                    }
                    else 
                    {
                        printf("\t\tNot valid - invalid student code\n");
                        result = 0;
                    }
                }
                else
                {
                    printf("\t\tNot valid - invalid year\n");
                    result = 0;
                }
            }
            else 
            {
                printf("\t\tNot valid - wrong middle digits\n");
                result = 0;
            }
        }
        else 
        {
            printf("\t\tNot valid - alphabetic character is prohibited\n");
            result = 0;
        }
    }
    else if (length > 11)
    {
        printf("\t\tNot valid - length is too long\n");
        result = 0;
    }
    else if (length < 11)
    {
        printf("\t\tNot valid - length is too short\n");
        result = 0;
    }

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
    int name_result = 0;    /*result of validation*/
    char inp_name[128];     /*recieve name from valName*/
    char name_cpy[128];     /*copy name from valName to validate*/

    do
    {
        printf("Enter Name to validate (Press * to exit) : ");
        fgets(inp_name,sizeof(inp_name),stdin);
        sscanf(inp_name,"%[^\n]s",name_cpy);
        if (strcmp(name_cpy,"*") == 0)
        {
            name_result = -1;
        }
        else
        {
            name_result = validateName(name_cpy);
            if(name_result == 1)
            {
                strcpy(valName,name_cpy);
            }
        }
    } while (name_result == 0);
    
    return name_result;
}

int stIDControl(char valID[128])
{
    int stID_result = 0;    /*result of validation*/
    char inp_stID[128];     /*recieve student ID from valID*/
    char stID_cpy[128];     /*copy student ID from valID to validate*/

    do
    {
        printf("Enter Student ID to validate (Press * to exit) : ");
        fgets(inp_stID,sizeof(inp_stID),stdin);
        sscanf(inp_stID,"%[^\n]s",stID_cpy);
        if (strcmp(stID_cpy,"*") == 0)
        {
            stID_result = -1;
        }
        else
        {
            stID_result = validateStID(stID_cpy);
            if(stID_result == 1)
            {
                strcpy(valID,stID_cpy);
            }
        }
    } while (stID_result == 0);
    
    return stID_result;
}