#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_all(int* haystack, int haystack_size, int needle){
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
    * haystack size can almost always be sizeof(haystack)/sizeof(int)
    */
    int count = 0;
    for (int i = 0; i < haystack_size; i++) {
        if (haystack[i] == needle) {
            count += 1;
        }
    }
    return count;   
}

char yesNo(char *prompt) {
    /*
    * Function: yesNo()
    * Programmer Name: Arianna Reischer
    * Date:11/3/2021
    * Preconditions:
    * string prompt is defined
    * Postconditions:
    * a char corresponding to the user input is returned
    * Globals: n/a
    * Returns: either the character 'y' or 'n' depending on the user input
    * Description: prompts the user for a yes or no answer and returns a character corresponding to the result
    */

	// Declares a character array (string) that will be later be filled by the user input
	char input[4];

	// Prompts the user for yes or no input until a valid response is entered
	while (1){
		printf("Enter yes or no: ");
        scanf("%s", input);

        // this converts input to lowercase
        for (int i = 0; i < sizeof(input)/sizeof(char); i++) {
            input[i] = tolower(input[i]);
        }
        
        // Checks if the string entered was yes, no, or neither
        if (strcmp(input, "yes") == 0) {
            return 'y';
        } else if (strcmp(input, "no") == 0) {
            return 'n';
        } else {
            printf("The input you entered isn't valid. Try again.\n");
        }
    }
}

int all_values_within_range(double* array, int array_size, int max, int min) {
    /*
    * Function: all_values_within_range()
    * Programmer Name: Bilal Zafar and Ben Fasick
    * Date:11/3/2021
    * Preconditions:
    * double* array, int array_size, int max, int min
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: int
    * Description: returns true (0) if all values within the array are between
    * min and max, inclusive, else returns false.
    */
    int count = 0;
    for (int i = 0; i < array_size; i++) {
        if ((array[i]-min)*(array[i]-max) <= 0) {
            count += 1;
        }
    }
    if (count == array_size) {
        return 0;
    } else {
        return 1;
    }
}