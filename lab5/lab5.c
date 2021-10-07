/*
* Programmer Name:     Ben Fasick
* Class and Semester:  CIS 1057 Fall 2021
* Date:                Wednesday, Octoberth, 2021
* Assignment:          Lab 4
*    Name:             Banking Change
*    Description:      Calculate change in US bills and coins with missing denominations..
*/
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
    /* this is the main algorithm. seeing as we aren't allowed to use if statements and
    * i figured trinary operators would be cheating, we just loop the amount dividing by
    * the bill amount and then subtracting the amount of change to be given in that
    * denomination. note for lab5 i elected loops were simply neccesary, but i did elect to only use them in the functions.
    * this lets our main function remain extremely linear
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
    get_change(amount, &twenties, &tens, &fives, &ones, &quarters, &dimes, &nickels, &pennies);
    elim_denoms(to_elim, denoms_num, &twenties, &tens, &fives, &ones, &quarters, &dimes, &nickels, &pennies);


    // inform user of output
    print_change(twenties, tens, fives, ones, quarters, dimes, nickels, pennies);

    // return 0 and quit
    return EXIT_SUCCESS;
}

void elim_denoms(char** array, int num_denoms, int *twenties, int *tens, int *fives, int *ones, int *quarters, int *dimes, int *nickels, int *pennies){
    int last_pos = num_denoms - 1;
    int second_last_pos = num_denoms - 2;

    if (strcmp(array[second_last_pos], "nickels") == 0 && strcmp(array[last_pos], "pennies") == 0){
        printf("You are out of nickels and pennies?\nKindly go to the bank, peasent.\n");
        exit(1);
    }
    printf("There are %d denominations to remove.\n", num_denoms);

    for (int i = 0; i < num_denoms; i++){
        char *denom = array[i];
        printf("Now removing %s as found in array[%d].\n", denom, i);
        if (strcmp(denom, "twenties") == 0){
            while (*twenties > 0){
                printf("twenties: %d, tens: %d\n", *twenties, *tens);
                *tens += 2;
                *twenties -= 1;
            }
        }
        if (strcmp(denom, "tens") == 0){
            while (*tens > 0){
                printf("tens: %d, fives: %d\n", *tens, *fives);
                *fives += 2;
                *tens -= 1;
            }
        }
        if (strcmp(denom, "fives") == 0){
            while (*fives > 0){
                printf("fives: %d, ones: %d\n", *fives, *ones);
                *ones += 5;
                *fives -= 1;
            }
        }
        if (strcmp(denom, "ones") == 0){
            while (*ones > 0){
                printf("ones: %d, quarters: %d\n", *ones, *quarters);
                *quarters += 4;
                *ones -= 1;
            }
        }
        if (strcmp(denom, "quarters") == 0){
            while (*quarters > 0){
                printf("quarters: %d, dimes: %d, nickels: %d\n", *quarters, *dimes, *nickels);
                *dimes += 2;
                *nickels += 1;
                *quarters -= 1;
            }
        }
        if (strcmp(denom, "dimes") == 0){
            while (*dimes > 0){
                printf("dimes: %d, nickels: %d\n", *dimes, *nickels);
                *nickels += 2;
                *dimes -= 1;
            }
        }
        if (strcmp(denom, "nickels") == 0){
            while (*nickels > 0){
                printf("nickels: %d, pennies: %d\n", *nickels, *pennies);
                *pennies += 5;
                *nickels -= 1;
            }
        }
        if (strcmp(denom, "pennies") == 0){
            while (*pennies > 0){
                *nickels += 1;
                *pennies -= 5;
            }
            *pennies = 0;
        }
    }
}

int get_denoms_num(){
    int i;
    printf("%s", "How many denominations are you out of?: ");
    scanf("%d", &i);
    return i;
}

char** get_missing_denoms(int denoms_num){
    /**
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
    *  note this really just lets the user create a 1-D array of strings, see my
    * stackoverflow post here: 
    * https://stackoverflow.com/questions/69475016/creating-a-1-d-array-of-strings-from-user-input-in-c
    **/
   char** array = malloc(denoms_num * sizeof(char*));
    for (int i = 0; i < denoms_num; i++) {
        char* temp = malloc(32);
        printf("Input missing denom %d of %d (type \"help\" for help): ", i, denoms_num);
        scanf("%s", temp);        
        if (strcmp(temp, "help") == 0){
            printf("%s", "The possibilities are twenties, tens, fives, ones, quarters, dimes, nickels, or pennies.\n");
            printf("%s", "If pennies is missing, the answer will be rounded up to the nearest nickel.\n");
            printf("%s", "Please input denoms one at a time in descending order.\n");
            exit(1);
        }
        array[i] = temp;
    }
    for (int m = 0; m < denoms_num; m++){
        printf("%s\n", array[m]);
    }
    return array;
}

void get_change(float amount, int *twenties, int *tens, int *fives, int *ones, int *quarters, int *dimes, int *nickels, int *pennies) {
    /**
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
    **/

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

    /* you may notice instead of dividing by by .01 here we do .009. this is due to the fact that
    * c hates us and a float of of 1.54 will be treated as 1.540004. because of this any change amount
    * divisible by .05 would return one less penny then neccessary. this would be easily remedied by
    * setting presicion on float (or the use of if) but all my attempts at using math.floor failed. this worked for all
    * test casses so ¯\_(ツ)_/¯
    */
    *pennies = (amount / .009);
    amount -= .01 * (*pennies);
}

void program_identification(char *name, char *date){
    /**
    * Function: program_identification()
    * Programmer Name: Ben Fasick
    * Date:9/22/2021
    * Preconditions:
    * a constant known as ASSIGNMENT_DESCRIPTION
    * Postconditions:
    * n/a
    * Globals: n/a
    * Returns: void
    * Description: Identifies the program with ASSIGNMENT_DESCRIPTION, the programmer's name, and the date.
    **/
    printf("This purpose of this program is to %s\n", ASSIGNMENT_DESCRIPTION);
    printf("This program was written by %s on %s.\n", name, date);
    return;
}

void print_change(int twenties, int tens, int fives, int ones, int quarters, int dimes, int nickels, int pennies){
    /**
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
    **/
    printf("You owe them \n%d twenties\n%d tens\n%d fives\n%d ones\n%d quarters\n%d dimes\n%d nickels\nand %d pennies.\n", twenties, tens, fives, ones, quarters, dimes, nickels, pennies);
    return;
}

float get_cash_amount(){
    /**
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
    **/
    float amount;
    printf("%s","Amount of change you need: $");
    scanf("%f", &amount);
    return(amount);
}