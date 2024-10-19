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

void printInternalLongInt(long int val) {
  printf("\033[35mMachine code of (long int = %ld)\033[0m: ", val);
  for (size_t i = 0; i < sizeof(long int); i++) {
    printBinary((unsigned char)(val >> (i * 8)));
  }
  printf("\n");
}

void printInternalLongDouble(long double val) {
  printf("\033[35mMachine code of (long double = %Lf)\033[0m: ", val);
  unsigned char *longDoubleBytes = (unsigned char *)&val;
  for (int i = 0; i < sizeof(long double); i++) {
    printBinary(longDoubleBytes[i]);
  }
  printf("\n");
}

void printInternalChar(char val) {
  printf("\033[35mMachine code of (char = '%c')\033[0m: ", val);
  printBinary((unsigned char)val);
  printf("\n");
}

void printInternalInt(int val) {
  printf("\033[35mMachine code of (int = %d)\033[0m: ", val);
  for (size_t i = 0; i < sizeof(int); i++) {
    printBinary((unsigned char)(val >> (i * 8)));
  }
  printf("\n");
}

void printInternalIntArray(int *arr, size_t size) {
  printf("\033[34mMachine code of array with int values\033[0m:\n\n");
  for (size_t i = 0; i < size; i++) {
    printf("Елемент %zu: ", i);
    printInternalInt(arr[i]);
  }
}

void task1() {
  long int longIntValue = 78L;
  long double longDoubleValue = 3.14159L;
  char charValue = 'A';

  int arr[5] = {1, -12, 3, 4, 5};

  highlightText("Machine code of values:", "blue");
  printf("\n");

  printInternalLongInt(longIntValue);
  printInternalLongDouble(longDoubleValue);
  printInternalChar(charValue);
  printf("\n");
  printInternalIntArray(arr, 5);
}