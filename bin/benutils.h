#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// prototypes (not needed in header files but it helps me keep track of shit)
// general utilities needed for class things
void program_identification(char*, char*, char*);
// input
int get_int_input();
char* get_str_input();
// arrays
int* get_range(int, int);
void print_int_array(int, int*);


void program_identification(char *name, char *date, char* description){
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
    printf("This purpose of this program is to %s\n", description);
    printf("This program was written by %s on %s.\n", name, date);
    return;
}

int get_int_input(){
    /*
    * Function: get_int_input()
    * Programmer Name: Ben Fasick
    * Date:10/18/2021
    * Preconditions:
    * n/a
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: int
    * Description: fetches and returns an int from the user
    */
    char num[8];
    int i;
    fgets(num, 7, stdin);
    // TODO: add error checking
    i = (int)strtol(num, NULL, 10);
    return i;
}

char* get_str_input(){
    /*
    * Function: get_str_input()
    * Programmer Name: Ben Fasick
    * Date:10/18/2021
    * Preconditions:
    * n/a
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: string
    * Description: fetches and returns a string from the user
    */
    char str[64] = {};
    char* s_ptr = str;
    scanf("%[^\n]s", str);
    return s_ptr;
}

int* get_range(int lower, int upper){
    if (upper <= lower){
        printf("The first parameter must be lower then then second.\n");
        exit(1);
    }
    int len;
    len = upper - lower;
    int* range = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++){
        range[i] = i;
    }
    return range;
}

void print_int_array(int array_size, int* array){
    printf("%s", "Inside print_int_array()\n");
    for (int i = 0; i < array_size; i++){
        printf("%d\n", array[i]);
    }
    return;
}