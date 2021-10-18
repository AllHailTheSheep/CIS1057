#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int get_int_input(){
    char num[8];
    int i;
    fgets(num, 7, stdin);
    // TODO: add error checking
    i = (int)strtol(num, NULL, 10);
    return i;
}

char* get_str_input(){
    char str[64] = {};
    char* s_ptr = str;
    scanf("%[^\n]s", str);
    return s_ptr;
}