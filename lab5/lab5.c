/*
* Programmer Name:     Ben Fasick
* Class and Semester:  CIS 1057 Fall 2021
* Date:                Wednesday, October 9th, 2021
* Assignment:          Lab 4
*    Name:             Banking Change
*    Description:      Calculate change in US bills and coins with missing denominations..
*/

// TODO: Add elim_denoms "base_denom" checker to enable elimination of pennies AND nickels etc.
// TODO: Add a log.
// TODO: Add type checks for user inputs.
// TODO: Find scanf alternative.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASSIGNMENT_DESCRIPTION "calculate change in US bills and coins with missing denominations."

// function prototypes
void program_identification(char *, char *);
void get_change(float, int *, int *, int *, int *, int *, int *, int *, int *);
int get_denoms_num();
char** get_missing_denoms(int);
void elim_denoms(char**, int, int *, int *, int *, int *, int *, int *, int *, int *);
float get_cash_amount();
void print_change();

int main(){
    /* note that i kind of bolted this on to lab4. however, it probably 
    * wouldve been faster to actually rewrite lab4 in a way more conducive
    * way for this assignment. however, thats less fun. i also strongly
    * considered using a custom struct data type called change instead
    * of a bunch of pointers.
    */

    // identify self
    program_identification("Ben Fasick", "October 6th 2021");

    // declare variables
    float amount;
    int twenties, tens, fives, ones, quarters, dimes, nickels, pennies;
    int denoms_num, i;

    // get amount to gibe in change and initialize variables
    amount = get_cash_amount();
    denoms_num = get_denoms_num();
    char** to_elim = malloc(denoms_num * sizeof(char*));
    to_elim = get_missing_denoms(denoms_num);

    // get change
    get_change(amount, &twenties, &tens, &fives, &ones, &quarters, &dimes, 
                &nickels, &pennies);

    // eliminate the denominations as specified in to_elim
    elim_denoms(to_elim, denoms_num, &twenties, &tens, &fives, &ones, 
                &quarters, &dimes, &nickels, &pennies);


    // inform user of output
    print_change(twenties, tens, fives, ones, quarters, dimes, nickels, 
                pennies);

    // do it again
    main();

    // the program will never execute this so it will never exit
    return EXIT_SUCCESS;
}

void elim_denoms(char** array, int num_denoms, int *twenties, int *tens, 
                int *fives, int *ones, int *quarters, int *dimes, int *nickels,
                int *pennies){
    /*
    * Function: get_missing_denoms()
    * Programmer Name: Ben Fasick
    * Date:10/7/2021
    * Preconditions:
    * variables for twenties, tens, fives, ones, quarters, dimes, nickels, and pennies that do have values
    * Postconditions:
    * variables for twenties, tens, fives, ones, quarters, dimes, nickels, and pennies that do have values
    * Globals: n/a
    * Returns: char** (array of strings)
    * Description: eliminate the denominations specified in array
    */

    // we're gonna need the indexes of the last and second to last
    int last_pos = num_denoms - 1;
    int second_last_pos = num_denoms - 2;

    if (strcmp(array[second_last_pos], "nickels") == 0 && 
        strcmp(array[last_pos], "pennies") == 0){
        
        /* are there ways i could eliminate dimes and pennies without
        * insulting the user? absolutely. however, i've found I simply don't
        * care. jokes aside, i'd reverse the array and create a function with
        * a bunch of if statements to walk through the reversed array and 
        * check if it's the next lowest denomination, and set the final one to
        * a sort of "base denomination" that we'd use rounding up. if i get
        * time i will resubmit with this feature (for posterity). 
        */
        printf("You are out of nickels and pennies?\nKindly go to the bank, peasent.\n");
        exit(1);
    }

    // i'd have this kind of thing go to logs to keep the output clear
    printf("There are %d denominations to remove.\n", num_denoms);

    // we will loop over each element in array (based on i our denom pointer
    // changes)
    for (int i = 0; i < num_denoms; i++){
        char *denom = array[i];

        // printf("Now removing %s as found in array[%d].\n", denom, i);

        // QUESTION: do you think it would be eastier to make all these 
        // reductions a function?

        // check if we need to remove twenties
        if (strcmp(denom, "twenties") == 0){
            // if we do, remove them
            while (*twenties > 0){
                printf("twenties: %d, tens: %d\n", *twenties, *tens);
                // for each twentie removed we need to add two tens
                *tens += 2;
                *twenties -= 1;
            }
        }

        // check if we need to remove tens
        if (strcmp(denom, "tens") == 0){
            // if we do, remove them
            while (*tens > 0){
                printf("tens: %d, fives: %d\n", *tens, *fives);
                // for each ten removed we need to add two fives
                *fives += 2;
                *tens -= 1;
            }
        }

        // check if we need to remove fives
        if (strcmp(denom, "fives") == 0){
            // if we do, remove them
            while (*fives > 0){
                printf("fives: %d, ones: %d\n", *fives, *ones);
                // for each five removed we need five ones
                *ones += 5;
                *fives -= 1;
            }
        }

        // check if we need to remove ones
        if (strcmp(denom, "ones") == 0){
            // if we do, remove them
            while (*ones > 0){
                printf("ones: %d, quarters: %d\n", *ones, *quarters);
                // for each one removed we need to add 4 quarters
                *quarters += 4;
                *ones -= 1;
            }
        }

        // check if we need to remove quarters
        if (strcmp(denom, "quarters") == 0){
            // if we do, remove them
            while (*quarters > 0){
                printf("quarters: %d, dimes: %d, nickels: %d\n", *quarters,
                        *dimes, *nickels);
                // for each quarter removed we need to add two dimes and one
                // nickel
                *dimes += 2;
                *nickels += 1;
                *quarters -= 1;
            }
        }

        // check if we need to remove dimes
        if (strcmp(denom, "dimes") == 0){
            // if we do, remove them
            while (*dimes > 0){
                printf("dimes: %d, nickels: %d\n", *dimes, *nickels);
                // for each dime removed we need to add two nickels
                *nickels += 2;
                *dimes -= 1;
            }
        }

        // check if we need to remove nickels
        if (strcmp(denom, "nickels") == 0){
            // if we do, remove them
            while (*nickels > 0){
                printf("nickels: %d, pennies: %d\n", *nickels, *pennies);
                // for each nickel removed we need 5 nickels
                *pennies += 5;
                *nickels -= 1;
            }
        }

        // check if we need to remove pennies
        if (strcmp(denom, "pennies") == 0){
            // if we do, remove them
            while (*pennies > 0){
                // for every five pennies removed we need to add one nickel
                *nickels += 1;
                *pennies -= 5;
            }
            // when the program reaches here, it means we need to remove
            // pennies and pennies <= zero. therefore negative numbers have 
            // already been acounted for and we can just set pennies to zero
            *pennies = 0;
        }
    }
}

int get_denoms_num(){
    /*
    * Function: get_denoms_num()
    * Programmer Name: Ben Fasick
    * Date:10/7/2021
    * Preconditions:
    * n/a
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: the number of missing denominations we should be prepared to
    * eliminatet
    * Description: gets the number of missing denominations we should be
    * prepared to eliminate
    */
    int i;
    printf("%s", "How many denominations are you out of?: ");
    // read input
    scanf("%d", &i);
    // return it
    return i;
}

char** get_missing_denoms(int denoms_num){
    /*
    * Function: get_missing_denoms()
    * Programmer Name: Ben Fasick
    * Date:10/7/2021
    * Preconditions:
    * n/a
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: char** (array of strings)
    * Description: gets the missing denoms in the form of an array of strings.
    * note this really just lets the user create a 1-D array of strings, see my
    * stackoverflow post here (shoutout brad): 
    * https://stackoverflow.com/questions/69475016/creating-a-1-d-array-of-strings-from-user-input-in-c
    */

    // in c we have to allocate for memory
    char** array = malloc(denoms_num * sizeof(char*));

    // this loop will get the users input and construct the array
    for (int i = 0; i < denoms_num; i++) {
        // 32 bytes is more then enough for us, as "twenties" is 8 bytes
        char* temp = malloc(32);

        // now we get input
        printf("Input missing denom %d of %d (type \"help\" for help): ", i,
                denoms_num);
        //read it into (no & because temp is alreadt a pointer)
        scanf("%s", temp);

        // people get confused really easily this should help at least a bit 
        if (strcmp(temp, "help") == 0){
            printf("%s", "The possibilities are twenties, tens, fives, ones, quarters, dimes, nickels, or pennies.\n");
            printf("%s", "If pennies is missing, the answer will be rounded up to the nearest nickel.\n");
            printf("%s", "Please input denoms one at a time in descending order.\n");
            exit(1);
        }
        // now read temp into the i index of array
        array[i] = temp;
    }
    for (int m = 0; m < denoms_num; m++){
        // this would be in logs
        // printf("%s\n", array[m]);
    }
    // return our newly constructed **char
    return array;
}

void get_change(float amount, int *twenties, int *tens, int *fives, int *ones,
                int *quarters, int *dimes, int *nickels, int *pennies) {
    /*
    * Function: get_change()
    * Programmer Name: Ben Fasick
    * Date:9/22/2021
    * Preconditions:
    * variables for twenties, tens, fives, ones, quarters, dimes, nickels, and pennies that don't have values
    * Postconditions:
    * variables for twenties, tens, fives, ones, quarters, dimes, nickels, and pennies that do have values
    * Globals: n/a
    * Returns: void
    * Description: gives values to money denomination variables that are add to the amount given.
    */

    /*
    * this is the main algorithm. seeing as we aren't allowed to use if statements and
    * i figured trinary operators would be cheating, we just loop the amount dividing by
    * the bill amount and then subtracting the amount of change to be given in that
    * denomination.
    */

    *twenties = (int)(amount) / 20;
    amount -= 20 * (*twenties);

    *tens = (int)(amount) / 10;
    amount -= 10 * (*tens);

    *fives = (int)(amount) / 5;
    amount -= 5 * (*fives);

    *ones = (int)amount / 1;
    amount -= 1 * (*ones);
    
    *quarters = amount / .25;
    amount -= .25 * (*quarters);

    *dimes = amount / .10;
    amount -= .10 * (*dimes);

    *nickels = amount / .05;
    amount -= .05 * (*nickels);

    /* 
    * you may notice instead of dividing by by .01 here we do .009. this is
    * due to the fact that c hates us and a float of of 1.54 will be treated 
    * as 1.540004. because of this any change amount divisible by .05 would
    * return one less penny then neccessary. this would be easily remedied by
    * setting presicion on float (or the use of if) but all my attempts at 
    * using math.floor failed. this worked for all test casses so ¯\_(ツ)_/¯
    */
    *pennies = (amount / .009);
    amount -= .01 * (*pennies);

    return;
}

void program_identification(char *name, char *date){
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
    printf("This purpose of this program is to %s\n", ASSIGNMENT_DESCRIPTION);
    printf("This program was written by %s on %s.\n", name, date);
    return;
}

void print_change(int twenties, int tens, int fives, int ones, int quarters, 
                    int dimes, int nickels, int pennies){
    /*
    * Function: program_identification()
    * Programmer Name: Ben Fasick
    * Date:9/28/2021
    * Preconditions:
    * n/a
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: void
    * Description: prints results of change needed when given the values of each denomination.
    */
    printf("You owe them \n%d twenties\n%d tens\n%d fives\n%d ones\n%d quarters\n%d dimes\n%d nickels\nand %d pennies.\n", twenties, tens, fives, ones, quarters, dimes, nickels, pennies);
    return;
}

float get_cash_amount(){
    /*
    * Function: prompt_for_cash_amount()
    * Programmer Name: Ben Fasick
    * Date:9/22/2021
    * Preconditions:
    * n/a
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: double
    * Description: reads and returns the amount of change needed.
    */
    float amount;
    printf("%s","Amount of change you need: $");
    // read input
    scanf("%f", &amount);
    // return it
    return(amount);
}