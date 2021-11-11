/*
* Programmer Name:     Ben Fasick
* Class and Semester:  CIS 1057 Fall 2021
* Date:                Tuesday November 11th, 2021
* Assignment:          Lab 9
*    Name:             Resistors
*    Description:      Create a program to decode resistor band combinations
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bin/benutils.h"
#include "resistors.h"

#define ASSIGNMENT_DESCRIPTION "create a program to decode resistor band combinations"

// function prototypes
char** get_bands();


int main() {
    // identify self
    program_identification("Ben Fasick", "11 November 2021", ASSIGNMENT_DESCRIPTION);

    printf("The supported band colors are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s, ", COLOR_CODES[i]);
    }
    printf("and none.\n");

    char** bands = malloc(4 * sizeof(char*));
    bands = get_bands();
    print_string_array(bands, 4);

    int bandsnum = 4 - count_all(bands, 4, "none");
    printf("Number of bands: %d\n", bandsnum);
    
    
    return EXIT_SUCCESS;
}

char** get_bands() {
    /*
    * Function: get_bands()
    * Programmer Name: Ben Fasick
    * Date:11/11/2021
    * Preconditions:
    * n/a
    * Postconditions:
    * a pre-allocated array
    * Globals: n/a
    * Returns: char**
    * Description: returns an array of 4 strings with color names.
    */
    // first allocate memory for the array
    char** array = malloc(4 * sizeof(char*));

    // we know there are 4 elements in the array
    for (int i = 1; i < 5; i++) {
        // allocate a temporary string
        char* band = malloc(32);
        // take the input
        printf("Input band %d of 4: ", i);
        scanf("%s", band);

        // convert it to lowercase
        for (int i = 0; i < sizeof(band)/sizeof(char); i++) {
            band[i] = tolower(band[i]);
        }
        
        // if "none" is entered the first two times, retry
        // if "none" is entered the third time, we assume the fourth is none
        // as well and retrun immediately
        if (strcmp(band, "none") == 0 && i == 1) {
            printf("There must be at least two bands!\n");
            array = get_bands();
            return array;
        } else if (strcmp(band, "none") == 0 && i == 2) {
            printf("There must be at least two bands!\n");
            i -= 1;
        } else if (strcmp(band, "none") == 0 && i == 3) {
            array[i-1] = band;
            array[i] = band;
            return array;
        } else if (strcmp(band, "none") == 0 && i == 4) {
            array[i-1] = band;
            return array;  
        } else {
            // we need to confirm that the color is valid
            // we don't need to check for none because any time none is entered
            // it will either repeat the iteration or return a full array
            // before it reaches here

            int count = 0;
            for (int i = 0; i < 10; i++) {
                if (strcmp(COLOR_CODES[i], band) == 0) {
                    count += 1;
                }
            }

            // if count is greater than 0 then the color is valid
            if (count > 0) {
                array[i-1] = band;
            } else {
                printf("That's not a valid band color. Try again.\n");
                i -= 1;
            }
        }
    }
    return array;
}