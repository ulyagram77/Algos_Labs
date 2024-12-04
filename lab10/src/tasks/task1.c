#include <stdio.h>
#include <stdlib.h>

#include "general_utils.h"
#include "hash_table_chained.h"

void task1()
{
  int search_key = 19;

  ht_init();

  FILE *file = fopen("data/data_20.txt", "r");
  if (file == NULL)
  {
    perror("Cannot open data file");
  }

  int id;
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  while (fscanf(file, "%d,%49[^,],%49[^\n]\n", &id, name, email) != EOF)
  {
    ht_insert(id, name, email);
  }
  fclose(file);

  highlightText("HASH TABLE WITH CHAINING", "blue");

  ht_print();

  highlightText("\nSEARCHING IN HASH TABLE WITH CHAINING\n", "blue");

  ht_linear_search(search_key);
  ht_linear_search_with_barrier(search_key);
}