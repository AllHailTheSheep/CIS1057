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

// assignment description
#define ASSIGNMENT_DESCRIPTION "Numeric tables generated on demand make it easy to understand the relation between ranges of numbers at a glance."

// function prototypes
void program_identification(char *, char *);
int obtain_user_integer_input(const char *);

int main(){
    //
    int low_row, low_col;
    low_row = obtain_user_integer_input("Enter low row number: ");
    low_col = obtain_user_integer_input("Enter low column number: ");
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

int obtain_user_integer_input(const char* message){
    printf("%s", message);
    char line[256];
    int i;
    if (fgets(line, sizeof(line), stdin)) {
        if (1 == sscanf(line, "%d", &i)) {
            return i;
        }
    }
}