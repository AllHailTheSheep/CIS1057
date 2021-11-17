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

// we are going to create a struct for out band details
struct resistor_info {
    double ohms, tolerance, low, high, multiplier;
    int tolerance_index, multiplier_index;
};

typedef struct resistor_info resistor;

// function prototypes
char** get_bands();
void analyze_bands(char**, int, resistor*);
void print_resistor(resistor);

int main() {
    // identify self
    program_identification("Ben Fasick", "11 November 2021", ASSIGNMENT_DESCRIPTION);

    printf("The supported band colors are:\n");
    for (int i = 0; i < 12; i++) {
        printf("%s, ", COLOR_CODES[i]);
    }
    printf("and none.\n");

    char** bands = malloc(5 * sizeof(char*));
    bands = get_bands();
    print_string_array(bands, 5);

    int bandsnum = 5 - count_all(bands, 5, "none");
    printf("Number of bands: %d\n", bandsnum);

    resistor r;
    resistor *r_ptr = &r;
    analyze_bands(bands, bandsnum, r_ptr);
    
    char* temp = malloc(32);
    // take the input
    printf("Do you want to analyze another resistor(y/n)?: ");
    scanf("%s", temp);
    for (int i = 0; i < sizeof(temp)/sizeof(char); i++) {
        temp[i] = tolower(temp[i]);
    }
    if (strcmp(temp, "y") == 0) {
        main();
    } else {
        return EXIT_SUCCESS;
    }
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
    char** array = malloc(5 * sizeof(char*));

    // we know there are 4 elements in the array
    for (int i = 1; i < 6; i++) {
        // allocate a temporary string
        char* band = malloc(32);
        // take the input
        printf("Input band %d of 5: ", i);
        scanf("%s", band);

        // convert it to lowercase
        for (int i = 0; i < sizeof(band)/sizeof(char); i++) {
            band[i] = tolower(band[i]);
        }
        
        // if "none" is entered the first three times, then we retrun the
        // iteration
        if (strcmp(band, "none") == 0 && i == 1) {
            printf("There must be at least three bands!\n");
            i -= 1;
        } else if (strcmp(band, "black") == 0 && i == 1) {
            printf("If the first band is black then your resistor is known as a wire.\n");
            i -= 1;
        } else if (strcmp(band, "none") == 0 && i == 2) {
            printf("There must be at least three bands!\n");
            i -= 1;
        } else if (strcmp(band, "none") == 0 && i == 3) {
            printf("There must be at least three bands!\n");
            i -= 1;
        } else if (strcmp(band, "none") == 0 && i == 4) {
            printf("Input band 5 of 5: none\n");
            array[i-1] = band;
            array[i] = band;
            return array;
        } else if (strcmp(band, "none") == 0 && i == 5) {
            array[i-1] = band;
            return array;
        } else if (strcmp(band, "black") == 0 && i == 5) {
            printf("The last band cannot be black!\n");
            i -= 1;
        } else {
            // we need to confirm that the color is valid
            // we don't need to check for none because any time none is entered
            // it will either repeat the iteration or return a full array
            // before it reaches here
            int count = 0;
            for (int i = 0; i < 12; i++) {
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

void analyze_bands(char** array, int bands_num, resistor *r) {
    // we will create a series of lists that we will reference.
    // we don't need a related list for color_codes because we the value is the
    // index
    char* color_codes[10] = {"black", "brown", "red", "orange",
                                "yellow","green", "blue", "violet",
                                "grey", "white"};

    // this is the reference for the multiplier bands
    char* multiplier_codes[10] = {"black", "brown", "red", "orange",
                                "yellow","green", "blue", "violet",
                                "gold", "silver"};
    // these are the correlating multiplier values
    double multiplier_values[10] = {1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0,
                                    1000000.0, 10000000.0, .1, .01};

    // this is the reference for the tolerance bands
    char* tolerance_codes[8] = {"brown", "red", "green", "blue", "violet",
                                "grey", "gold", "silver"};
    // these are the corrlating tolerance values
    double tolerance_values[8] = {1.0, 2.0, 0.5, 0.25, 0.1, 0.05, 5.0, 10.0};
    
    // set the reference indexes in the struct
    r->tolerance_index = bands_num - 1;
    r->multiplier_index = bands_num - 2;
    // allocate for ohms string
    char* ohms = malloc(8 * sizeof(char));

    // iterate through the bands present
    for (int i = 0; i < bands_num; i++) {
        if (i < r->multiplier_index) {
            // if i < multiplier_index then we concat the corresponding index
            // of color_codes to ohms
            int index = get_index(color_codes, 10, array[i]);
            printf("Regular band %d is %s with value %d\n", i + 1, array[i], index);
            char temp[2];
            // make sure theres no trailing newline
            snprintf(temp, sizeof(temp), "%d", index);
            temp[strcspn(temp, "\n")] = 0;
            // add temp to ohms
            strcat(ohms, temp);
        } else if (i == r->multiplier_index) {
            // get the value to multiply by
            int index = get_index(multiplier_codes, 10, array[i]);
            if (index != -1) {
                r->multiplier = multiplier_values[index];
                printf("Mutiplier band is %s with value %f\n", array[i], r->multiplier);
            } else {
                printf("%s is an unknown multiplier band color.\n",
                        multiplier_codes[index]);
                main();
            }
        } else if (i == r->tolerance_index) {
            // get the tolerance value
            int index = get_index(tolerance_codes, 7, array[i]);
            if (index >= 0) {
                r->tolerance = tolerance_values[index];
                printf("Tolerance band is %s with value %f\n", array[i], r->tolerance);
            } else {
                printf("%s is  an unkown tolerance band color.\n", array[i]);
                main();
            }
        }
    }
    double temp;
    char *eptr;
    // convert our ohms string to a double
    temp = strtod(ohms, &eptr);
    // assign the results to our struct
    r->ohms = temp * r->multiplier;
    double difference = r->ohms * (r->tolerance/100);
    r->low = r->ohms - difference;
    r->high = r->ohms + difference;
    print_resistor(*r);
    // printf("ohms: %f\ndifference: %f\nlow: %f\nhigh: %f\n", r->ohms, difference,
    // r->low, r->high);
    return;
}

void print_resistor(resistor r) {
    printf("Resistance: %f ohms\n", r.ohms);
    printf("Tolerance: +/-%f%%\n", r.tolerance);
    printf("Resistor range: %f - %f ohms\n", r.low, r.high);
    return;
}