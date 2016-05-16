
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
#include <time.h>

/*
 * Chapter 10, Exercise 12
 * 
 * Write a function called strToFloat that converts a character string into a
 * floating point value. Have the function accept an optional leading minus.
 * So, the call
 * 
 * strToFloar("-867.6921");
 * 
 * should return the value -867.6921
 */

// flag the start of the decimal point !!!???

double strToFloat(char string[]) { // type cast???
    int i, j, decpnt;
    double floatValue, result = 0;
    
    // handle minus
    if (string[0] == '-') {
       for (i = 1; string[i] >= '.' && string[i] <= '9'; ++i) {
           if (string[i] == '/') { //skip the backslash
                i++;
                continue;
            } else if (string[i] == '.') { //skip the decimal point
                decpnt = i - 1; // mark start of decimal point(-1 because for i = 1)
                continue;
            }    
           
           floatValue = string[i] - '0';
           result = result * 10 + floatValue;  
       }
       
       for (j = 0; result >= 1; j++) {
            result /= 10;
        }
        
        for (int m = 0; m < decpnt; m++) {
            result *= 10;
        } 
       
       return -result;
    } else {                  // calculate positive floating point number      
        for (i = 0; string[i] >= '.' && string[i] <= '9'; ++i) {
            
            if (string[i] == '/') { //skip the backslash
                i++;
                continue;
            } else if (string[i] == '.') { //skip the decimal point
                decpnt = i;     // from where decimal point starts
                continue;
            }
            floatValue = string[i] - '0';
            result = result * 10 + floatValue; 
        }
        // 
        for (j = 0; result >= 1; j++) {  
            result /= 10;
        }
        // place the decimal point
        for (int m = 0; m < decpnt; m++) {
            result *= 10;
        }        
        
        //insert decimal point in appropriate place
       return result; 
    }    
    
}

int main(int argc, char** argv) {
    
    for (int i = 0; i < 100000; i++) {
        printf("%f", strToFloat("123456.78\n")); // working
    }
    
    return (EXIT_SUCCESS);
}

/*
 * Ideas:
 * 
 * 1. Decimal count isn't used 
 */