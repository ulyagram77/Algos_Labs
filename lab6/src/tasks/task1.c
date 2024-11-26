#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "general_utils.h"
#include "string_block-linked.h"
#include "string_vector.h"

int countWordsOfLengthK(const char *str, size_t k) {
  int count = 0;
  size_t wordLength = 0;
  const char *s = str;

  while (*s) {
    if (isalpha(*s)) {
      wordLength++;
    } else {
      if (wordLength == k) {
        count++;
      }
      wordLength = 0;
    }
    s++;
  }

  if (wordLength == k) {
    count++;
  }

  return count;
}

double measureExecutionTime(int (*func)(const char *, size_t), const char *str,
                            size_t k) {
  clock_t start = clock();
  func(str, k);
  return ((double)(clock() - start) / CLOCKS_PER_SEC) * 1000;
}

void benchmark(const char *str, int dublicates) {
  int k = 3; // searching words length

  BlockString *blockStr = init_block_string();
  VectorString *vectorStr = init_vector_string(10);

  for (int i = 0; i < dublicates; i++) {
    append_to_vector_string(vectorStr, str);
    append_to_block_string(blockStr, str);
  }

  char *parsedBlockStr = get_block_string(blockStr);

  double vectorTime =
      measureExecutionTime(countWordsOfLengthK, vectorStr->data, k);
  double blockTime =
      measureExecutionTime(countWordsOfLengthK, parsedBlockStr, k);

  printf("\nWord count of length %zu in vector string: %d\n", k,
         countWordsOfLengthK(vectorStr->data, k));
  printf(
      "Execution time \033[34m(vector string)\033[0m: \033[32m%.2f ms\033[0m\n",
      vectorTime);
  printf("Memory used: \033[32m%zu bytes\033[0m\n", vectorStr->size);

  printf("\nWord count of length %zu in block string: %d\n", k,
         countWordsOfLengthK(parsedBlockStr, k));
  printf(
      "Execution time \033[34m(block string)\033[0m: \033[32m%.2f ms\033[0m\n",
      blockTime);
  printf("Memory used: \033[32m%zu bytes\033[0m\n\n", blockStr->size);

  free(parsedBlockStr);
  destroy_block_string(blockStr);
  destroy_vector_string(vectorStr);
}

void task1() {
  int k = 3;
  BlockString *blockStr = init_block_string();
  VectorString *vectorStr = init_vector_string(10);

  highlightText("VECTOR STRING IMPLEMENTATION", "blue");

  append_to_vector_string(vectorStr, "Glory ");
  append_to_vector_string(vectorStr, "to ");
  append_to_vector_string(vectorStr, "Ukraine");
  append_to_vector_string(vectorStr, "!");

  print_vector_string(vectorStr);

  printf("\n");
  highlightText("BLOCK-LINKED STRING IMPLEMENTATION", "blue");

  append_to_block_string(blockStr, "Glory ");
  append_to_block_string(blockStr, "to ");
  append_to_block_string(blockStr, "Ukraine");
  append_to_block_string(blockStr, "!");

  print_block_string(blockStr);

  printf("\n");
  highlightText("MEMORY AND ESTIMATE TIME TEST OF STRING DATA STRUCTURES",
                "blue");

  benchmark("Cat was sad but ate pie. ", 1000);
  puts("-------------------------------------------");
  benchmark("Cat was sad but ate pie. ", 10000);
  puts("-------------------------------------------");
  benchmark("Cat was sad but ate pie. ", 100000);

  destroy_block_string(blockStr);
  destroy_vector_string(vectorStr);
}