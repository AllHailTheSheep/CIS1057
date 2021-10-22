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
#include <math.h>
#include "../bin/benutils.h"

// assignment description
#define ASSIGNMENT_DESCRIPTION "Numeric tables generated on demand make it easy to understand the relation between ranges of numbers at a glance."

// function prototypes
int obtain_user_integer_input(const char *);
char* obtain_operator_input(void);

int perform_int_operation(int, int, char*);
double perform_double_operation(int, int, char*);

int main(){
    // identify self
    program_identification("Ben Fasick", "Monday October 18th", ASSIGNMENT_DESCRIPTION);
    // print supported operators
    printf("%s%s%s%s%s%s%s%s%s", "The following operators and their meanings are supported:\n",
                                "  +: addition\n",
                                "  -: subtraction\n",
                                "  x,X,*: multiplication\n",
                                "  /: division\n",
                                "  D: integer division\n"
                                "  %: modulo\n",
                                "  p: row value raised to the column power\n",
                                "  r: column root of the row value\n",
                                "  h: display this message\n\n");
    
    // declare variables
    int x_low, x_high, y_low, y_high;
    char operator[2];

    // get the user input we need
    x_low = obtain_user_integer_input("Enter the x low number: ");
    x_high = obtain_user_integer_input("Enter x high column number: ");
    y_low = obtain_user_integer_input("Enter the y low number: ");
    y_high = obtain_user_integer_input("Enter the y high number: ");
    strcpy(operator, obtain_operator_input());

    // summarize collected info after some quick validation
    char* operators = "+-xX*/D\%prh";
    char* operator_pos = strstr(operators, operator);
    if (operator_pos == NULL){
        printf("'%s' is not a valid operator.\nPlease re-run the program.\n", operator);
        exit(1);
    }
    if (x_low < x_high == 0 || y_low < y_high == 0){
        printf("x_low(%d) must be less then x_high(%d) and y_low(%d) must be less then y_high(%d).\n", x_low, x_high, y_low, y_high);
        exit(1);
    }
    // printf("x = %d-%d\ny = %d-%d\noperator = '%s'\n", x_low, x_high, y_low, y_high, operator);
    
    // now get the ranges and print them
    int x_len;
    int y_len;
    x_len = x_high - x_low + 1;
    y_len = y_high - y_low + 1;
    int* x_range = malloc(sizeof(int) * x_len);
    int* y_range = malloc(sizeof(int) * y_len);
    for (int i = 0; i < x_len; i++){
        x_range[i] = x_low + i;
    }
    for (int i = 0; i < y_len; i++){
        y_range[i] = y_low + i;
    }

    // print_int_array(x_range, x_len);
    // print_int_array(y_range, y_len);

    // now heres where things get interesting
    // some of our operators have the potential of returning doubles
    // we need to be able to deal with that
    char* double_operator_pos = strstr("/r", operator);

    if (double_operator_pos == NULL){
        printf("%s is not a double operator.\n", operator);
    } else {
        printf("%s is a double operator.\n", operator);
    }
    return 0;
}

double perform_double_operation(int thing1, int thing2, char* operator){
    double output;
    if (strcmp(operator, "/") == 0){
        output = thing1 / thing2;
    } else if (strcmp(operator, "r") == 0){
        output = pow(thing1, 1/thing2);
    }
    return output;
}

int perform_int_operation(int thing1, int thing2, char* operator){
    int output;
    if (strcmp(operator, "+") == 0){
        output = thing1 + thing2;
    } else if (strcmp(operator, "-") == 0){
        output = thing1 - thing2;
    } else if (strcmp(operator, "x") == 0){
        output = thing1 * thing2;
    } else if (strcmp(operator, "X") == 0){
        output = thing1 * thing2;
    } else if (strcmp(operator, "*") == 0){
        output = thing1 * thing2;
    } else if (strcmp(operator, "%") == 0){
        output = thing1 % thing2;
    } else if (strcmp(operator, "p") == 0){
        output = pow(thing1, thing2);
    }
    return output;
}

char* obtain_operator_input(void){
    /*
    * Function: obtain_user_operator_input()
    * Programmer Name: Ben Fasick
    * Date:10/18/2021
    * Preconditions:
    * n/a
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: string
    * Description: returns a string after asking 
    */
    printf("%s", "Enter the operator to generate the table (enter 'h' for help): ");

    char *str;
    str = get_str_input("");
    
    char help[2] = "h";
    if (strcmp(str, help) == 0){
        printf("%s%s%s%s%s%s%s%s%s%s", "The following operators and their meanings are supported:\n",
                                    "  +: addition\n",
                                    "  -: subtraction\n",
                                    "  x,X,*: multiplication\n",
                                    "  /: division\n",
                                    "  D: integer division\n"
                                    "  %: modulo\n",
                                    "  p: row value raised to the column power\n",
                                    "  r: column root of the row value\n",
                                    "  h: display this message\n\n");
        exit(1);
    } else {
        return str;
    }
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
    int i;
    i = get_int_input();
    if (i < -15 || i > 15) {
        printf("Please enter an integer between -15 and 15.\n");
        obtain_user_integer_input(message);
    } else {
        return i;
    }
}