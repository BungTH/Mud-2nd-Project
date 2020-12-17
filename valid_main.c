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