#include <stdio.h>
#include <stdlib.h>

#include "general_utils.h"
#include "dyn_arr.h"
#include "time.h"

void print_array(DynArr *arr)
{
  for (int i = 0; i < arr->size; i++)
  {
    int *value = (int *)get_elem_dyn_arr(arr, i);
    if (i == 0)
    {
      printf("[ %d ", *value);
    }
    else if (i == arr->size - 1)
    {
      printf(" %d ]", *value);
    }
    else
    {
      printf(" %d ", *value);
    }
  }

  printf("\nArray size: %d\n", arr->size);
}

void generate_arr_data(DynArr *arr)
{
  for (int i = 0; i < arr->capacity; i++)
  {
    int *value = (int *)malloc(sizeof(int));
    *value = generateRandomInt(1, 99);
    push_dyn_arr(arr, value);
  }
}

void measure_execution_time(int (*func)(DynArr *arr, const char *order), const DynArr *arr, const char *order)
{
  clock_t start = clock();
  func(arr, order);
  clock_t end = clock();

  double time_taken_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
  printf("\033[32m\033[0m Estimated time: \033[32m%.2f\033[0m ms\n", time_taken_ms);
}

void gnome_sort(DynArr *arr, const char *order)
{
  int index = 0;
  int swap_count = 0;
  int comparison_count = 0;

  int ascending = (strcmp(order, "asc") == 0);

  while (index < arr->size)
  {
    int *current = (int *)get_elem_dyn_arr(arr, index);

    comparison_count++;
    if (index == 0 ||
        (ascending ? *(int *)get_elem_dyn_arr(arr, index - 1) <= *current
                   : *(int *)get_elem_dyn_arr(arr, index - 1) >= *current))
    {
      index++;
    }
    else
    {
      int *prev = (int *)get_elem_dyn_arr(arr, index - 1);
      int temp = *prev;
      *prev = *current;
      *current = temp;

      swap_count++;
      index--;
    }
  }

  print_array(arr);
  if (ascending)
  {
    printf("\n\033[32m\033[0m Sorting order: \033[32m%s\033[0m\n", order);
  }
  else
  {
    printf("\n\033[32m\033[0m Sorting order: \033[32m%s\033[0m\n", order);
  }

  printf("\033[32m󰓡\033[0m Number of swaps: \033[32m%d\033[0m\n", swap_count);
  printf("\033[32m\033[0m Number of comparisons: \033[32m%d\033[0m\n", comparison_count);
}

void task1()
{
  srand(time(NULL));
  int ARR_SIZE = 50000;

  DynArr *int_arr = init_dyn_arr(sizeof(int), ARR_SIZE);

  generate_arr_data(int_arr);
  highlightText("DYNAMIC ARRAY OF INT VALUES", "blue");
  print_array(int_arr);

  highlightText("\nDYNAMIC ARRAY OF INT VALUES AFTER GNOME SORT", "blue");
  measure_execution_time(gnome_sort, int_arr, "asc");

  destroy_dyn_arr(int_arr);
}