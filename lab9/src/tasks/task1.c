#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linked_list.h"
#include "general_utils.h"

int int_comparer(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

void fill_linked_list(Node **head, int size)
{
  for (int i = 0; i < size; i++)
  {
    int *value = (int *)malloc(sizeof(int));
    *value = generateRandomInt(1, 10000);
    insert_head_linked_list(head, value);
  }
}

void test_search(Node **head, void *key, CompareFunc comparer, int (*search_func)(Node *, void *, CompareFunc))
{
  clock_t start = clock();
  int comparisons = search_func(*head, key, comparer);
  clock_t end = clock();

  double time_taken_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

  if (comparisons > 0 && comparisons <= 10000)
  {
    printf("Key found. Comparisons: %d \n\033[34m\033[0m Time: \033[32m%.3f\033[0m milliseconds\n", comparisons, time_taken_ms);
  }
  else
  {
    printf("Key not found. Comparisons: %d \n\033[34m\033[0m Time: \033[32m%.3f\033[0m milliseconds\n", comparisons, time_taken_ms);
  }
}

int linear_search_linked_list(Node *head, void *key, CompareFunc comparer)
{
  int comparisons = 0;
  Node *current = head;

  while (current)
  {
    comparisons++;
    if (comparer(current->data, key) == 0)
    {
      return comparisons;
    }
    current = current->next;
  }
  return comparisons;
}

int linear_search_with_barrier(Node **head, void *key, CompareFunc comparer)
{
  if (!*head)
  {
    return 0;
  }

  insert_head_linked_list(head, key);
  int comparisons = 0;
  Node *current = *head;

  while (current)
  {
    comparisons++;
    if (comparer(current->data, key) == 0)
    {
      break;
    }
    current = current->next;
  }

  delete_node_linked_list(head, key, comparer, NULL);
  return comparisons;
}

void free_int_data(void *data)
{
  free(data);
}

void task1()
{
  srand(time(NULL));

  int sizes[] = {20, 100, 1000, 10000};
  int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

  for (int i = 0; i < num_sizes; i++)
  {
    int size = sizes[i];
    Node *head = NULL;

    printf("\n\033[34mTesting for list size: %d\033[0m\n", size);
    fill_linked_list(&head, size);

    int key = generateRandomInt(1, 1000);
    printf("Searching for key: %d\n\n", key);

    printf("\033[34m\033[0m Linear Search \033[34m\033[0m\n");
    test_search(&head, &key, int_comparer, linear_search_linked_list);
    puts("");
    printf("\033[34m\033[0m Linear Search with Barrier \033[34m\033[0m\n");
    test_search(&head, &key, int_comparer, (int (*)(Node *, void *, CompareFunc))linear_search_with_barrier);
    puts("\n------------------------------");

    destroy_linked_list(&head, free_int_data);
  }

  return 0;
}