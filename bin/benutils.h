#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// prototypes (not needed in header files but it helps me keep track of shit)
// general utilities needed for class things
void program_identification(char*, char*, char*); // identifies the program
// input
double get_double_input(char*); // take double input
int get_int_input(char*); // take int input
char* get_str_input(char*); // returns a string after prompting for input
// arrays
void print_int_array(int*, int); // prints an int array
void print_double_array(double*, int); // prints a double array
void print_string_array(char**, int); // prints a string array
void print_2d_string_array(char***, int, int); // prints a 2d string array
// general functions
int get_index(char**, int, char*); // returns the index of needle
int count_all(char**, int, char*); // returns the number of times x occurrs in the array

void program_identification(char *name, char *date, char* description) {
    /*
    * Function: program_identification()
    * Programmer Name: Ben Fasick
    * Date:9/22/2021
    * Preconditions:
    * a string for name, date, and description
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: void
    * Description: Identifies the program with ASSIGNMENT_DESCRIPTION, the 
    * programmer's name, and the date.
    */
    printf("This purpose of this program is to %s\n", description);
    printf("This program was written by %s on %s.\n", name, date);
    return;
}

double get_double_input(char* message) {
    /*
    * Function: get_int_input()
    * Programmer Name: Ben Fasick
    * Date:10/18/2021
    * Preconditions:
    * message to be printed, or NULL
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: int
    * Description: fetches and returns an double from the user
    */
    double number;
    do {
        printf("%s", message);
        scanf("%*c"); // burn stdin so as not to buffer up responses
    } while (1 != scanf("%lf", &number));
    return number;
}

int get_int_input(char* message) {
    /*
    * Function: get_int_input()
    * Programmer Name: Ben Fasick
    * Date:10/18/2021
    * Preconditions:
    * message to be printed, or NULL
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: int
    * Description: fetches and returns an int from the user
    */
    int number;
    do {
        printf("%s", message);
        scanf("%*c"); // burn stdin so as not to buffer up responses
    } while (1 != scanf("%d", &number));
    return number;
}

char* get_str_input(char* message) {
    /*
    * Function: get_str_input()
    * Programmer Name: Ben Fasick
    * Date:10/18/2021
    * Preconditions:
    * message to be printed, or NULL
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: string
    * Description: fetches and returns a string from the user
    */
    char* string;
    do {
        printf("%s", message);
        scanf("%*c"); // burn stdin so as not to buffer up responses
    } while (1 != scanf("%s", string));
}

void print_int_array(int* array, int array_size) {
    /*
    * Function: print_int_array()
    * Programmer Name: Ben Fasick
    * Date:10/20/2021
    * Preconditions:
    * int* array and int array_size
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: void
    * Description: prints an int array
    */
    for (int i = 0; i < array_size; i++) {
        if (i != array_size - 1) {
            printf("%d, ", array[i]);
        } else {
            printf("%d", array[i]);
        }
    }
    printf("\n");
    return;
}

void print_double_array(double* array, int array_size) {
    /*
    * Function: print_double_array()
    * Programmer Name: Ben Fasick
    * Date: 11/6/2021
    * Preconditions:
    * double* array and int array_size
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: void
    * Description: prints a double array
    */
    for (int i = 0; i < array_size; i++) {
        if (i != array_size - 1) {
            printf("%lf, ", array[i]);
        } else {
            printf("%lf", array[i]);
        }
    }
    printf("\n");
    return;
}

void print_string_array(char** array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        if (i != array_size - 1) {
            printf("%s, ", array[i]);
        } else {
            printf("%s", array[i]);
        }
    }
    printf("\n");
    return;
}

void print_2d_string_array(char*** array, int array_x, int array_y) {
    /*
    * Function: print_char_array()
    * Programmer Name: Ben Fasick
    * Date:11/1/2021
    * Preconditions:
    * 2d char array in array and its demensions in i and j
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: void
    * Description: prints an i x j char array
    */
   
    for (int x = 0; x < array_x; x++) {
        for (int y = 0; y < array_y; y++) {
            printf("%s", array[x][y]);
            int len = strlen(array[x][y]);
            for (int i = 0; i < 16 - len; i++) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int get_index(char** haystack, int haystack_size, char* needle) {
    /*
    * Function: get_index()
    * Programmer Name: Ben Fasick
    * Date:11/15/2021
    * Preconditions:
    * int* haystack, int haystack_size, int needle
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: int
    * Description: returns the index that the needle last appears at. if needle
    * does not appear in haystack, the return value is -1.
    */

    // printf("looking for %s in haystack\n", needle);
    int index = -1;
    for (int i = 0; i < haystack_size; i++) {
        if (strcmp(haystack[i], needle) == 0) {
            index = i;
            // printf("found %s at index %d\n", needle, index);
        }
    }
    return index;   
}

int count_all(char** haystack, int haystack_size, char* needle) {
    /*
    * Function: count_all()
    * Programmer Name: Ben Fasick
    * Date:11/1/2021
    * Preconditions:
    * int* haystack, int haystack_size, int needle
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: int
    * Description: counts the amount of times needle appears in haystack.
    */
    int count = 0;
    for (int i = 0; i < haystack_size; i++) {
        if (strcmp(haystack[i], needle) == 0) {
            count += 1;
        }
    }
    return count;   
}