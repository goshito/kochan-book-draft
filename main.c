/* The purpose of this program is to remove some elements from an array
 * I am trying to accomplish that 
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[81];
    int start_pos, chars_to_remove, end_point, end_of_string, i, j;
    char removal_result[81];
    
    printf("Enter string: ");
    gets(str);
    //scanf("%s", str);
    
    printf("\nFrom which character to start removal?\n");
    scanf("%i", &start_pos);
    
    printf("\nHow many chars would you like to remove?\n");
    scanf("%i", &chars_to_remove);
    
    // Copy entered string elements until start position is reached
    i = 0;
    while (i < start_pos) {
        removal_result[i] = str[i];
        i++;
    }
    
    end_point = i + chars_to_remove;
    end_of_string = strlen(str);
    
    while (end_point <= end_of_string) {
        removal_result[i] = str[end_point];
        end_point++;
        i++;
    }
    
    printf("Here's what you've done: %s", removal_result);
    
    return 0;
}
/*     printf("\nend_point: %i\n", end_point);
    printf("\nend of string: %i\n", end_of_string); */
