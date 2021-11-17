#include <stdlib.h>
#include <stdio.h>

#define IN_MAIN

#ifdef IN_MAIN
const char COLOR_CODES[12][7] = {"black", "brown", "red", "orange",
                                "yellow","green", "blue", "violet",
                                "grey", "white", "gold", "silver"};
#else
extern char COLOR_CODES[12][7];
#endif