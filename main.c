#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
float strToFloar(char input[]) {
    return (float)(atof(input));
}
/*
int digitsAfterDecimalPoint(double x) {
    int i;
    for (i = 0; x != rint(x); x += x, i++);
    return i;
}*/

int main () {
    printf("%f\n", strToFloar("867.6921"));
    printf("%f\n", strToFloar("867.6921"));
    //printf("\n%f", digitsAfterDecimalPoint("867.6921") % 10);
 
   return 0;
}

/* 
 * Ideas:
 *
 * 1. Round the float result  
 */