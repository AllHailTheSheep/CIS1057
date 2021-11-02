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

// TODO: add other functions