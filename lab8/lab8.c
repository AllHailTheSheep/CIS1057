/*
* Programmer Name:     Ben Fasick
* Class and Semester:  CIS 1057 Fall 2021
* Date:                Wednesday, November 10, 2021
* Assignment:          Lab 8
*    Name:             Boiling Point
*    Description:      To create a program that will take a temperture and
                        compate it to a database then return the material
                        with the corresponding boiling point
*/

// assignment description
#define ASSIGNMENT_DESCRIPTION "return the material with a boiling point corresponding to the entered temperature"

#include <stdlib.h>
#include <stdio.h>
#include "../bin/benutils.h"

int main() {
    // identify self
    program_identification("Ben Fasick", "November 1st 2021", ASSIGNMENT_DESCRIPTION);
    

    char* substances[13] = {"Carbon dioxide", "Ammonia", "Wax", "Water", 
                            "Olive Oil", "Mercury", "Sulfur", "Talc", "Silver",
                            "Copper", "Gold", "Iron", "Silicon"};

    char* boiling_points[13] = {"-78.5", "-35.5", "45", "100.7", "300", "356.9",
                            "444.6", "1500", "2212", "2562", "2700", "2862",
                            "3280"};

    char*** array;
    array = malloc(sizeof(char**) * 13);
    for (int i = 0; i < 13; i++){
        array[i] = malloc(sizeof(char*) * 2);
    }

    // fill our array
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                array[i][j] = substances[i];
            } else {
                array[i][j] = boiling_points[i];
            }
        }
    }


    // this is a print thing
    print_char_array(array, 13, 2);

    return 0;

}