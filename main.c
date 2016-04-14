/*
 * Chapter 10, Exercise 6 segmentation fault
 */

#include <stdio.h>
#include <string.h>

void removeString(char string[], int start_pos, int n) {
    int i, end_pos, end_of_string;
    char rm_result[81];
    
    i = 0;
    while (i < start_pos) {
        rm_result[i] = string[i];
        i++;
    }
    
    end_pos = i + n;
    end_of_string = strlen(string);
    
    while (end_pos <= end_of_string) {
        rm_result[i] = string[n];
        n++;
        i++;
    }
    
    int size_string = strlen(string);
    int size_rm_result = strlen(rm_result);
    
    i = 0;
    while (i < size_string) {
        string[i] = rm_result[i];
        i++;
    }   
    
}

int main(void) {
    char test[] = "the wrong son";
    
    removeString(test, 4, 6);
    
    printf("test = %s", test);
    
    return 0;
}