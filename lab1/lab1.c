/*
* Programmer Name:     Ben Fasick
* Class and Semester:  CIS 1057 Fall 2021
* Date:                Wednesday, September 1st, 2021
* Assignment:          Lab 1
*    Name:             Temperature Conversion
*    Description:      Prompt for input, convert Fahrenheit to Celsius, display output.
*/

#include <stdio.h>
#include <stdlib.h>

#define CELSIUS_ADJUSTMENT 0.5555555

int main(){
	double fahrenheit, celsius;
	
	// print a banner telling the interactive user about us
	puts("TEMPERATURE CONVERSION");
	puts("This program will convert a Fahrenheit temperature to Celsius.");
	
	// prompt for input from the user
	printf("Enter a temperature in fahrenheit: ");
	scanf ("%lf", &fahrenheit);
	
	// perform the calculation to convert temperature
	celsius = (fahrenheit - 32.0) * CELSIUS_ADJUSTMENT;
	
	// display the results
	printf("%0.2lf degrees fahrenheit is %0.2lf in celsius.\n", fahrenheit, celsius);
	printf("        %lfF = %lfC.\n", fahrenheit, celsius);
	return EXIT_SUCCESS;
}
