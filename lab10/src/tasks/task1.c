#include <stdio.h>
#include <stdlib.h>

#include "general_utils.h"
#include "hash_table_chained.h"

void task1()
{
  // Инициализация хеш-таблицы
  ht_init();

  // Считывание данных из файла
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

  // Демонстрация работы
  printf("Хеш-таблица:\n");
  ht_print();

  // Поиск элемента
  printf("\nВведите ID для поиска: ");
  scanf("%d", &id);
  // Node *result = ht_search(id);
  // if (result != NULL)
  // {
  //   printf("Найдено: ID: %d, Name: %s, Email: %s\n", result->id, result->name, result->email);
  // }
  // else
  // {
  //   printf("Элемент с ID %d не найден.\n", id);
  // }

  ht_linear_search(id);
  ht_linear_search_with_barrier(id);
}