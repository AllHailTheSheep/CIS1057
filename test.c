#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char raw[2];
    fgets(raw, 2, stdin);
    char operator[2];
    strcpy(operator, raw);
    char help[2] = "h";
    printf("'%s'\n'%s'\n", operator, help);
    int res = strcmp(operator, help);
    printf("%d\n", res);
    return 0;
}