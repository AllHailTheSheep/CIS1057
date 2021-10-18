/*
* Programmer Name:     Ben Fasick
* Class and Semester:  CIS 1057 Fall 2021
* Date:                Wednesday, October 13th, 2021
* Assignment:          Lab 6
*    Name:             Numeric Input
*    Description:      Numeric tables generated on demand make it easy to
                        understand the relation between ranges of numbers at a
                        glance.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// assignment description
#define ASSIGNMENT_DESCRIPTION "Numeric tables generated on demand make it easy to understand the relation between ranges of numbers at a glance."

// function prototypes
int obtain_user_integer_input(const char *);
char* obtain_operator_input(void);
void program_identification(char *, char *);

int main(){
    int low_row, low_col;
    char operator[2];
    low_row = obtain_user_integer_input("Enter low row number: ");
    low_col = obtain_user_integer_input("Enter low column number: ");
    strcpy(operator, obtain_operator_input());

    printf("low_row = %d\nlow_col = %d\noperator = '%c'\n", low_row, low_col, operator);

    char help[2] = "h";
    printf("'%c'\n'%c'\n", operator, help);
    if (strcmp(operator, help) == 0){
        printf("%s", "So far so good...\n");
        printf("%s%s%s%s%s%s%s%s%s%s", "The following operators and their meanings are supported:\n",
                                    "  +: addition\n",
                                    "  -: subtraction\n",
                                    "  x,X,*: multiplication\n",
                                    "  /: division\n",
                                    "  D: integer division\n",
                                    "  %: modulo\n",
                                    "  p: row value raised to the column power\n",
                                    "  r: column root of the row value\n",
                                    "  h: display this message\n\n");
        exit(1);
    }
}

char* obtain_operator_input(void){
    printf("%s", "Enter the operator to generate the table (enter 'h' for help): ");

    char str[2] = {};
    char* s_ptr = str;
    scanf("%[^\n]s", str);
    printf("%s", str);
    
    return s_ptr;
}

int obtain_user_integer_input(const char* message){
    /*
    * Function: obtain_user_integer_input()
    * Programmer Name: Ben Fasick
    * Date:10/13/2021
    * Preconditions:
    * a const char* passed in
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: int
    * Description: returns an integer after printing the mesaage passed in.
    */
    printf("%s", message);
    char num[8];
    int i;
    fgets(num, 7, stdin);
    // TODO: add error checking
    i = (int)strtol(num, NULL, 10);
    return i;
}

void program_identification(char *name, char *date)
{
    /*
    * Function: program_identification()
    * Programmer Name: Ben Fasick
    * Date:9/22/2021
    * Preconditions:
    * a constant known as ASSIGNMENT_DESCRIPTION
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: void
    * Description: Identifies the program with ASSIGNMENT_DESCRIPTION, the 
    * programmer's name, and the date.
    */
    printf("This purpose of this program is to %s\n", ASSIGNMENT_DESCRIPTION);
    printf("This program was written by %s on %s.\n", name, date);
    return;
}