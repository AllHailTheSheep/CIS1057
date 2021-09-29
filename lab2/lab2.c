/*
* Programmer Name: Ben Fasick
* Class and Smemster: CIS 1057 Fall 2021
* Date: Wednesday September 8th, 2021
* Assignment: Lab 2
*    Name: Pythagorean Triples
*    Description: Given m and n where m > n, generate a Pythagorean triple.
*/

#include <stdio.h>
#include <math.h>

double _side1(double m, double n) {
    // this function calculates m^2-n^2
    double result;
    result = pow(n, 2) - pow(m, 2);
    return result;
}

double _side2(double m, double n) {
    // this function calculates 2mn
    double result;
    result = 2*m*n;
    return result;
}

double _hypotenuse(double m, double n) {
    // this function calculates m^2 + n^2
    double result;
    result = pow(m, 2) + pow(n, 2);
    return result;
}

int main() {
    // declare doubles
    double m, n, side1, side2, hypotenuse;
    
    // define m and n
    printf("Enter m and n, seperated by a single space: ");
    scanf("%lf %lf", &m, &n);
    
    // send m and n to our functions, pass results to our variables
    side1 = _side1(m, n);
    side2 = _side2(m, n);
    hypotenuse = _hypotenuse(m, n);
    
    // print our results
    printf("The Pythagorean triple for m = %lf and n = %lf is a = %lf, b = %lf, and c = %lf.\n", m, n, side1, side2, hypotenuse);
    
    // return successful exit code
    return 0;
}
