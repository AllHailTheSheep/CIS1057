#include <stdlib.h>
#include <stdio.h>

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
    for (int i = 0; i < haystack_size; i++){
        if (haystack[i] == needle){
            count += 1;
        }
    }
    return count;   
}

 

char yesNo (char *prompt) {
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
        
        // Checks if the string entered was yes, no, or neither
        if (strcmp(input, "yes") == 0 || strcmp(input, "Yes") == 0) {
            return 'y';
        } else if (strcmp(input, "no") == 0 || strcmp(input, "No") == 0) {
            return 'n';
        } else {
            printf("The input you entered isn't valid. Try again.\n");
        }
    }
}


// TODO: add other functions