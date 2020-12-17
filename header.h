typedef struct
{
    char stID[32];          /*student ID*/
    char name[128];         /*name of student*/
    char date[32];          /*date of birth*/
    char home[16];          /*province code*/
    char gpa[16];           /*GPA of student*/
    char gender[2];         /*gender of student*/
} DATA_T;

DATA_T textdata;

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

/*
    function for display data

    will take nothing as it's argument
    return nothing
*/
void display();

/*
    function for adding data

    will take nothing as it's argument
    return nothing
*/
void add();

/*
    function for search data

    will take nothing as it's argument
    return nothing
*/
void search();