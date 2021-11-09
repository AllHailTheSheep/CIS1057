#include <stdlib.h>
#include <stdio.h>
#include "group1.h"
#include "../bin/benutils.h"

#define ASSIGNMENT_PURPOSE "test the functions defined in group1.h"

int main(){
    // identify self
    program_identification("Ben Fasick, et. al.", "1 November 2021",
                            ASSIGNMENT_PURPOSE);
    // tests for count_all()
    // there will be three test cases, and each will test search for 0 to n-1

    // case test 1
    int test1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 3, 4, 5};
    printf("test1 = ");
    print_int_array(test1, sizeof(test1)/sizeof(int));
    for (int i = 0; i < sizeof(test1)/sizeof(int); i++){
        int test1_i = count_all(test1, sizeof(test1)/sizeof(int), i);
        printf("searching for %d in test1: found it %d times.\n", i, test1_i);
    }
    printf("\n");

    // case test 2 
    int test2[] = {0, 1, 1, 0, 0, 1, 1, 2};
    printf("test2 = ");
    print_int_array(test2, sizeof(test2)/sizeof(int));
    for (int i = 0; i < sizeof(test2)/sizeof(int); i++){
        int test2_i = count_all(test2, sizeof(test2)/sizeof(int), i);
        printf("searching for %d in test2: found it %d times.\n", i, test2_i);
    }
    printf("\n");

    // case test 3
    int test3[] = {99, 9999, 99999, 1, 0, 1};
    printf("test3 = ");
    print_int_array(test3, sizeof(test3)/sizeof(int));
    for (int i = 0; i < sizeof(test3)/sizeof(int); i++){
        int test3_ = count_all(test3, sizeof(test3)/sizeof(int), i);
        printf("searching for %d in test3: found it %d times.\n", i, test3_);
    }
    printf("\n");

    // tests for yesNo
    printf("yesNo will run 5 times.\nTry entering yes, no, yES, NO, ect.\n");
    for (int i = 0; i < 5; i++){
        char res;
        printf("Iteration %d\n", i);
        res = yesNo("Enter yes or no: ");
        printf("The function returned %c.\n", res);
    }

    // tests for all_values_within_range()
    double array1[] = {0.0, 100.0, 1000.0};
    
    print_double_array(array1, sizeof(array1)/sizeof(double));
    printf("min: %d\nmax: %d\nresult: %d\n", 0, 9999,
            all_values_within_range(array1, sizeof(array1)/sizeof(double), 0, 9999));

    print_double_array(array1, sizeof(array1)/sizeof(double));
    printf("min: %d\nmax: %d\nresult: %d\n", 0, 10,
            all_values_within_range(array1, sizeof(array1)/sizeof(double), 0, 10));
    
    double array2[] = {1.0, 2.5, 1000.0, 1500.015, 99.875, 100.011};

    print_double_array(array2, sizeof(array2)/sizeof(double));
    printf("min: %d\nmax: %d\nresult: %d\n", 1, 1500,
            all_values_within_range(array1, sizeof(array1)/sizeof(double), 1, 1500));
    
    print_double_array(array2, sizeof(array2)/sizeof(double));
    printf("min: %d\nmax: %d\nresult: %d\n", 0, 1600,
            all_values_within_range(array1, sizeof(array1)/sizeof(double), 0, 1600));
    
    return EXIT_SUCCESS;
}