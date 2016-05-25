#include <stdio.h>

int main(void) {
    int count = 10;
    int *int_pointer; // define a variable which is a pointer to int
    /*setup the indirect reference between int_pointer and count.
     Assign to int_pointer not the variable count but a pointer to it*/
    int_pointer = &count;
    int x;
    
    x = *int_pointer;
    printf("%i\n", x);
    
    return 0;
}