#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/*
    function for province validation

    will take string of provice code to validate
    return result of validation and display error if invalid
*/
int validateProvice(char proviceValue[128]);

/*
    function for GPA validation

    will take string of GPA to validate
    return result of validation and display error if invalid
*/
int validateGPA(char gpaValue[128]);

/*
    function for gender validation

    will take string of gender to validate
    return result of validation and display error if invalid
*/
int validateGender(char genderValue[128]);

/*
    control function for province validation

    will take string of province code to further sent it to validate function
    return result of validation and value back to called function by pharsing
*/
int provinceControl(char valProvince[128]);

/*
    control function for GPA validation

    will take string of GPA to further sent it to validate function
    return result of validation and value back to called function by pharsing
*/
int gpaControl(char valGPA[128]);

/*
    control function for gender validation

    will take string of gender to further sent it to validate function
    return result of validation and value back to called function by pharsing
*/
int genderControl(char valGender[128]);



int validateProvince(char provinceValue[128])
{
    int result = 0;         /*result of validation*/
    int i = 0;              /*loop counter*/
    int length;             /*recieve length of input from provinceValue*/
    int province_code;      /*recieve code from provinceValue*/
    const int format[77] = {10,37,15,38,31,24,18,36,22,50,57,20,86,46,62,71,40,81,52,51,
                         42,16,58,44,49,26,73,48,30,60,80,55,96,39,43,12,13,94,82,93,56,
                         67,76,66,65,54,14,83,25,77,85,70,21,45,27,47,11,74,75,19,91,17,
                         33,90,64,72,84,32,63,92,23,34,41,61,53,95,35};
                            /*format of province code*/

    length = strlen(provinceValue);
    if (length == 4)
    {
        if (strcmp(provinceValue,"TH-S") == 0)
        {
            printf("\t\tValid Data\n");
            result = 1;
        }
        else 
        {
            printf("\t\tNot valid - wrong format of province code\n");
        }
    }
    else if (length == 5)
    {
        if ((provinceValue[0] == 'T') && (provinceValue[1] == 'H') && (provinceValue[2] == '-'))
        {
            if ((isdigit(provinceValue[3])) && (isdigit(provinceValue[4])))
            {
                sscanf(provinceValue,"TH-%d",&province_code);
                for (i = 0;i < 77;i++)
                {
                    if (province_code == format[i])
                    {
                        result = 1;
                        break;
                    }
                    else
                    {
                        result = 0;
                    }
                }
                if (result == 1)
                {
                    printf("\t\tValid Data\n");
                    result = 1;
                }
                else
                {
                    printf("\t\tNot valid - wrong format of province code (nn part)\n");
                    result = 0;
                }
            }
            else if ((provinceValue[3] == 'I') && (provinceValue[4] == 'N'))
            {
                printf("\t\tValid Data\n");
                result = 1;
            }
            else
            {
                printf("\t\tNot valid - alphabetic character is prohibited\n");
                result = 0;
            }
        }
        else
        {
            printf("\t\tNot valid - wrong format of province code (TH- part)\n");
            result = 0;
        }
    }
    else 
    {
        printf("\t\tNot valid - format must be 4 or 5 character long\n");
        result = 0;
    }

    return result;
}

int validateGPA(char gpaValue[128])
{
    int result = 0;         /*result of validation*/
    int i = 0;              /*loop counter*/
    int digit_check = 0;    /*result of digit check*/
    int length;             /*recieve length of input from gpaValue*/
    int dot_count = 0;      /*count number of dot*/
    double gpa;             /*recieve gpa value from gpaValue*/

    length = strlen(gpaValue);
    for (i = 0;i < length;i++)
    {
        if (gpaValue[i] == '.')
        {
            dot_count++;
            continue;
        }
        else if (isdigit(gpaValue[i]))
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
        if (dot_count <= 1)
        {
            sscanf(gpaValue,"%lf",&gpa);
            if ((gpa <= 4) && (gpa >= 0))
            {
                printf("\t\tValid Data\n");
                result = 1;
            }
            else
            {
                printf("\t\tNot valid - GPA is out of range\n");
                result = 0;
            }
        }
        else 
        {
            printf("\t\tNot valid - there must be 0 or 1 dot in GPA\n");
            result = 0;
        }
    }
    else 
    {
        printf("\t\tNot valid - alphabetic character is prohibited\n");
        result = 0;
    }

    return result;
}

int validateGender(char genderValue[128])
{
    int result = 0;         /*result of validation*/
    int length;             /*recieve length of input from genderValue*/

    length = strlen(genderValue);
    if (length == 1)
    {
        if ((genderValue[0] == 'M') || (genderValue[0] == 'F') || (genderValue[0] == 'O'))
        {
            printf("\t\tValid Data\n");
            result = 1;
        }
        else 
        {
            printf("\t\tNot valid - other character beside M, F, O is not allowed\n");
            result = 0;
        }
    }
    else
    {
        printf("\t\tNot valid - format must be 1 character long\n");
        result = 0;
    }

    return result;
}

int provinceControl(char valProvince[128])
{
    int province_result = 0;/*result of validation*/
    char inp_province[128]; /*recieve province from valProvince*/
    char province_cpy[128]; /*copy province code from valProvince to validate*/

    do
    {
        printf("Enter Province code to validate (Press * to exit) : ");
        fgets(inp_province,sizeof(inp_province),stdin);
        sscanf(inp_province,"%[^\n]s",province_cpy);
        if (strcmp(province_cpy,"*") == 0)
        {
            province_result = -1;
        }
        else
        {
            province_result = validateProvince(province_cpy);
            if(province_result == 1)
            {
                strcpy(valProvince,province_cpy);
            }
        }
    } while (province_result == 0);
    
    return province_result;
}

int gpaControl(char valGpa[128])
{
    int gpa_result = 0;     /*result of validation*/
    char inp_gpa[128];      /*recieve gpa from valGpa*/
    char gpa_cpy[128];      /*copy gpa from valGpa to validate*/

    do
    {
        printf("Enter GPA to validate (Press * to exit) : ");
        fgets(inp_gpa,sizeof(inp_gpa),stdin);
        sscanf(inp_gpa,"%[^\n]s",gpa_cpy);
        if (strcmp(gpa_cpy,"*") == 0)
        {
            gpa_result = -1;
        }
        else
        {
            gpa_result = validateGPA(gpa_cpy);
            if(gpa_result == 1)
            {
                strcpy(valGpa,gpa_cpy);
            }
        }
    } while (gpa_result == 0);
    
    return gpa_result;
}

int genderControl(char valGen[128])
{
    int gender_result = 0;  /*result of validation*/
    char inp_gender[128];   /*recieve gender from valGen*/
    char gender_cpy[128];   /*copy gender from valGen to validate*/

    do
    {
        printf("Enter Gender to validate (Press * to exit) : ");
        fgets(inp_gender,sizeof(inp_gender),stdin);
        sscanf(inp_gender,"%[^\n]s",gender_cpy);
        if (strcmp(gender_cpy,"*") == 0)
        {
            gender_result = -1;
        }
        else
        {
            gender_result = validateGender(gender_cpy);
            if(gender_result == 1)
            {
                strcpy(valGen,gender_cpy);
            }
        }
    } while (gender_result == 0);
    
    return gender_result;
}