#include <stdlib.h>
#include <stdio.h>

#define IN_MAIN

#ifdef IN_MAIN
const char COLOR_CODES[10][7] = {"black", "brown", "red", "orange",
                                "yellow","green", "blue", "violet",
                                "grey", "white"};
#else
extern char COLOR_CODES[10][7];
#endif