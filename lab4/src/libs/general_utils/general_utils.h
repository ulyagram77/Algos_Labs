#ifndef GENERAL_UTILS_H
#define GENERAL_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generateRandomInt(int min, int max);
float generateRandomFloat(float min, float max);
void highlightText(const char *text, const char *color);
void printBinary(unsigned char byte);

#endif