#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "general_utils.h"

void printBinary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        int bit = (byte >> i) & 1;
        printf("%d", bit);
    }
    printf(" ");
}

void printInternalRepresentation(long int longIntValue, long double longDoubleValue, char charValue) {
    printf("Внутрішнє подання:\n");

    printf("Машинне представлення (long int = %ld): ", longIntValue);
    for (int i = 0; i < sizeof(long int); i++) {
        printBinary((unsigned char)(longIntValue >> (i * 8)));
    }
    printf("\n");

    printf("Машинне представлення (long double = %.2Lf): ", longDoubleValue);
    unsigned char *longDoubleBytes = (unsigned char*)&longDoubleValue;
    for (int i = 0; i < sizeof(long double); i++) {
        printBinary(longDoubleBytes[i]); 
    }
    printf("\n");

    printf("Машинне представлення (char = '%c'): ", charValue);
    printBinary((unsigned char)charValue);
    printf("\n");
}

void task1() {
    long int longIntValue = 42L;            
    long double longDoubleValue = 3.14159L;  
    char charValue = 'A';                    

    printInternalRepresentation(longIntValue, longDoubleValue, charValue);
}