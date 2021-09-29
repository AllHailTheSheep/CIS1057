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

#define KELVIN_ADJUSTMENT 0.5555555 + 273.15

int main(){
	double fahrenheit, kelvin;
	
	// print a banner telling the interactive user about us
	puts("TEMPERATURE CONVERSION");
	puts("This program will convert a Fahrenheit temperature to Kelvin.");
	
	// prompt for input from the user
	printf("Enter a temperature in fahrenheit: ");
	scanf ("%lf", &fahrenheit);
	
	// perform the calculation to convert temperature
	kelvin = (fahrenheit - 32.0) * KELVIN_ADJUSTMENT;
	
	// display the results
	printf("%0.2lf degrees fahrenheit is %0.2lf in Kelvin.\n", fahrenheit, kelvin);
	printf("        %lfF = %lfK.\n", fahrenheit, kelvin);
	return EXIT_SUCCESS;
}
