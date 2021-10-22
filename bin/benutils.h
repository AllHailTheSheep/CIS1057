#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// prototypes (not needed in header files but it helps me keep track of shit)
// general utilities needed for class things
void program_identification(char*, char*, char*);
// input
int get_int_input();
char* get_str_input(char*);
// arrays
void print_int_array(int*, int);

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
    if (i == 0){
        num[strcspn(num, "\n")] = 0;
        printf("Are you sure %s is a number?\n", num);
        exit(1);
    } else {
    return i;
    }
}

char* get_str_input(char* message){
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
    printf ("%s", message);
    char* temp = malloc(sizeof(char) * 32);
    scanf("%s", temp);
    // TODO: add testing to temp
    return temp;
}

void print_int_array(int* array, int array_size){
    for (int i = 0; i < array_size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}
