#include "general_utils.h"

int generateRandomInt(int min, int max) {
  return min + rand() % (max - min + 1);
}

float generateRandomFloat(float min, float max) {
  return ((float)rand() / RAND_MAX) * (max - min) + min;
}

void printBinary(unsigned char byte) {
  for (int i = 7; i >= 0; i--) {
    int bit = (byte >> i) & 1;
    printf("%d", bit);
  }
  printf(" ");
}

void measureTime(void (*func)(void *), void *arg) {
  clock_t start, end;
  double speed_time;

  start = clock();
  func(arg);
  end = clock();

  speed_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
  printf("Час виконання функції: \033[32m%.3f\033[0m мілісекунд.\n\n",
         speed_time);
}

void highlightText(const char *text, const char *color) {
  if (color == NULL || text == NULL) {
    printf("%s\n", text);
    return;
  }

  const char *colorCode;

  switch (color[0]) {
  case 'b':
    if (strcmp(color, "blue") == 0) {
      colorCode = "\033[34m";
    } else {
      colorCode = "";
    }
    break;
  case 'r':
    if (strcmp(color, "red") == 0) {
      colorCode = "\033[31m";
    } else {
      colorCode = "";
    }
    break;
  case 'g':
    if (strcmp(color, "green") == 0) {
      colorCode = "\033[32m";
    } else {
      colorCode = "";
    }
    break;
  case 'y':
    if (strcmp(color, "yellow") == 0) {
      colorCode = "\033[33m";
    } else {
      colorCode = "";
    }
    break;
  default:
    colorCode = "";
    break;
  }

  if (strlen(colorCode) > 0) {
    printf("%s%s\033[0m\n", colorCode, text);
  } else {
    printf("%s\n", text);
  }
}
