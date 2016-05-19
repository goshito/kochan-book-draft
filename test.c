//Pesho ver.4
#include <stdio.h>

double strToFloat(char string[]) {
    double result = 0;
    int decimalDivisor = 0, i = 0;
   for (; string[i] != 0; i++) {
       if (string[i] >= '0' && string[i] <= '9') {
           if(decimalDivisor) {
               decimalDivisor *= 10;
               result += (float)(string[i] - '0') / decimalDivisor;
           } else {
               result = result * 10 + (string[i] - '0');
           }
       } else if (string[i] == '.') {
           decimalDivisor = 1;
       }
    }
   return result;
}

int main(void) {
    printf("%f\n", strToFloat("123456.78"));
    
    return 0;
}