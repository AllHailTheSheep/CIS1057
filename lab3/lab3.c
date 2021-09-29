/*
* Programmer Name:     Ben Fasick
* Class and Semester:  CIS 1057 Fall 2021
* Date:                Wednesday, September 22st, 2021
* Assignment:          Lab 3
*    Name:             Swapping Integers
*    Description:      Demonstrate the swapping of two variables.
*/

#include <stdio.h>
#include <stdlib.h>

#define ASSIGNMENT_DESCRIPTION "Demonstrate the swapping of two variables."

// function prototypes
int get_int_value(char *prompt);
void program_identification(char *name, char *date);
void full_swap(int var_a, int var_b);

int main( ){
    program_identification("Ben Fasick", "September 22nd 2021");
    int first_number, second_number;
    
    // prompt and read the numbers in from the keyboard.
    first_number= get_int_value( "Enter first integer value:");
    second_number= get_int_value( "Enter second integer value:");
    
    full_swap(first_number, second_number);
    return EXIT_SUCCESS;
}

void program_identification(char *name, char *date){
    /**
    * Function: program_identification()
    * Programmer Name: Ben Fasick
    * Date:9/22/2021
    * Preconditions:
    * a constant known as ASSIGNMENT_DESCRIPTION
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: void
    * Description: Identifies the program with ASSIGNMENT_DESCRIPTION, the programmer's name, and the date.
    **/
    printf("This purpose of this program is to %s\n", ASSIGNMENT_DESCRIPTION);
    printf("This program was written by %s on %s.\n", name, date);
    return;
}

int get_int_value( char *prompt){
    /**
    * Function: get_int_value()
    * Programmer Name: Raymond Lauff
    * Date:9/22/2021
    * Preconditions:
    * n/a
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: int
    * Description: reads and returns int value after giving the user a prompt. 
    **/
    int v1;
    printf("%s ", prompt);
    scanf("%d", &v1);

    // Echoprint our input to ensure we've read it correctly from the user
    printf("\nEcho printing, read in the number = %d\n\n", v1);
    return(v1);
}

void full_swap(int var_a, int var_b) {
    /**
    * Function: full_swap()
    * Programmer Name: Ben Fasick
    * Date:9/22/2021
    * Preconditions:
    * n/a
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: void
    * Description: swaps the contents of the variables var_a and var_b using the XOR operator.
    * Where common addition/subtraction can overflow, giving negative results, XOR cannot.
    **/
    printf("The numbers before swap are (%d, %d).\n", var_a, var_b);
    var_a ^= var_b;
    var_b ^= var_a;
    var_a ^= var_b;
    printf("The numbers after swap are (%d, %d).\n", var_a, var_b);
    return;
}
