
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on May 4, 2016, 1:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*
 * !!! Peter's version of the program
 * 
 * Chapter 10, Exercise 12 Attempting to DRY 14052016 1857, 15052016 1504,1712
 * 
 * Write a function called strToFloat that converts a character string into a
 * floating point value. Have the function accept an optional leading minus.
 * So, the call
 * 
 * strToFloar("-867.6921");
 * 
 * should return the value -867.6921
 */



double strToFloat(char string[]) { 
    int i = 0, decpnt;
    double floatValue, result = 0;

    /* handle minus and plus */
    if (string[0] == '-' || string[0] == '+')
        i++;
    /* convert string to int*/
    for (; (string[i] >= '0' && string[i] <= '9') || string[i] == '.'; i++) {

        if (string[i] == '.') { /* skip the decimal and start dividing by 10 */
            if (string[0] == '-' || string[0] == '+') {
                decpnt = i - 1; /* mark start of decimal point(-1 because for i = 1)*/
            } /*divide the number n times*/
            else {                
                decpnt = i;
            }
            continue;
        }

        floatValue = string[i] - '0';
        result = result * 10 + floatValue;
        
    }
    
    if (string[0] == '+' || string[0] == '-')
        i--;
    
	int x = i - decpnt - 1;
	result = result * 1/(pow(10, x));    

    if (string[0] == '-')
        return -result;
    else
        return result;

}

int main(int argc, char** argv) {
    
    for (int i = 0; i < 100000; i++)
        printf("%f\n", strToFloat("123456.78"));   

    return (EXIT_SUCCESS);
}

