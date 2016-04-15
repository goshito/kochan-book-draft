/*
 *  Chapter 10, Exercise 7, alpha ver. (without functions)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char source[] = "the wrong son";
    int sourceSize = strlen(source);
    char insert[] = "per";
    int insertSize = strlen(insert);
    int pos, n = sourceSize + insertSize;
    char result[n];
    
    printf("\nInitial source size: %i", sourceSize);
    
    pos = 10;
    source[pos + 3] = source[pos];
    printf("%c", source[pos + 3]);
    pos++;
    source[pos + 3] = source[pos];
    printf("%c", source[pos + 3]);
    pos++;
    source[pos + 3] = source[pos];
    printf("%c", source[pos + 3]);
    
    pos = 10;
    source[pos] = insert[0];
    pos++;
    source[pos] = insert[1];
    pos++;
    source[pos] = insert[2];
    
    printf("\nsource: %s", source);
    
    return 0;
}
    
    
    