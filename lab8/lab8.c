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

// function prototypes
char* check_data(double, int);

#include <stdlib.h>
#include <stdio.h>
#include "../bin/benutils.h"

int main() {
    // identify self
    program_identification("Ben Fasick", "November 1st 2021", ASSIGNMENT_DESCRIPTION);
    while (1) {
        double data;
        int percent;
        data = get_double_input("Enter your observed boiling point (9999 to exit): ");
        if ((int)data == 9999) {exit(0);}
        percent = get_int_input("Enter your tolerance (usually 4): ");

        char* res;
        res = check_data(data, percent);
        if (strcmp(res, "Unknown") == 0) {
            printf("%f is not a boiling point of a known substance.\n", data);
            printf("Please enter a new value and try again.\n");
        } else {
            printf("A boiling point of %f means your substance is probably %s.\n",
            data, res);
        }
    }
    return 0;
}

char* check_data(double data, int percent) {
    char* substances[13] = {"Carbon dioxide", "Ammonia", "Wax", "Water", 
                            "Olive Oil", "Mercury", "Sulfur", "Talc", "Silver",
                            "Copper", "Gold", "Iron", "Silicon"};

    char* boiling_points[13] = {"-78.5", "-35.5", "45", "100.7", "300", "356.9",
                            "444.6", "1500", "2212", "2562", "2700", "2862",
                            "3280"};

    for (int i = 0; i < 13; i++) {
        double min = strtod(boiling_points[i], NULL) - percent;
        double max = strtod(boiling_points[i], NULL) + percent;
        if((data-min)*(data-max) <= 0){
            return substances[i];
        }
    }
    return "Unknown";
}