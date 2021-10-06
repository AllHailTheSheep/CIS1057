/*
* Programmer Name:     Ben Fasick
* Class and Semester:  CIS 1057 Fall 2021
* Date:                Wednesday, September 28th, 2021
* Assignment:          Lab 4
*    Name:             Banking Change
*    Description:      Calculates change in US bills and coins.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASSIGNMENT_DESCRIPTION "Calculate change in US bills and coins."

// function prototypes
void program_identification(char *, char *);
void get_change(float, int *, int *, int *, int *, int *, int *, int *, int *);
void elim_denoms(char[]);
float prompt_for_cash_amount();
void print_change();

int main(){
    /* this is the main algorithm. seeing as we aren't allowed to use if statements and
    * i figured trinary operators would be cheating, we just loop the amount dividing by
    * the bill amount and then subtracting the amount of change to be given in that
    * denomination.
    */
    // identify self
    program_identification("Ben Fasick", "October 4th 2021");

    // declare variables
    float amount;
    int twenties, tens, fives, ones, quarters, dimes, nickels, pennies;

    // get amount to gibe in change and initialize variables
    amount = prompt_for_cash_amount();

    // get change
    get_change(amount, &twenties, &tens, &fives, &ones, &quarters, &dimes, &nickels, &pennies);

    // inform user of output
    print_change(twenties, tens, fives, ones, quarters, dimes, nickels, pennies);

    // return 0 and quit
    return EXIT_SUCCESS;
}

void elim_denoms(char array[]){

}

void get_change(float amount, int *twenties, int *tens, int *fives, int *ones, int *quarters, int *dimes, int *nickels, int *pennies) {
    /**
    * Function: get_change()
    * Programmer Name: Ben Fasick
    * Date:9/22/2021
    * Preconditions:
    * variables for twenties, tens, fives, ones, quarters, dimes, nickels, and pennies that don't have values
    * Postconditions:
    * variables for twenties, tens, fives, ones, quarters, dimes, nickels, and pennies that don't have values
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

float prompt_for_cash_amount(){
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