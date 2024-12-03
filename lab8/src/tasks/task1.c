#include <stdio.h>
#include <stdlib.h>

#include "general_utils.h"
#include "priority_queue_arr.h"
#include "priority_queue_list.h"

void task1()
{
  PriorityQueue pq = init_priority_queue(5);
  LPQ *lpq = init_lpq();

  push_priority_queue(&pq, 10, 1);
  push_priority_queue(&pq, 20, 4);
  push_priority_queue(&pq, 15, 2);
  push_priority_queue(&pq, 69, 5);

  enqueue_lpq(lpq, 10, 1);
  enqueue_lpq(lpq, 20, 4);
  enqueue_lpq(lpq, 15, 2);
  enqueue_lpq(lpq, 69, 5);

  highlightText("Elements of LIST base priority queue:\n", "blue");
  print_lpq(lpq);
  printf("Memory allocated: \033[34m%zu\033[0m bytes\n", lpq->allocated_memory);
  puts("");

  highlightText("Elements of ARRAY priority queue:\n", "blue");
  print_priority_queue(&pq);
  printf("Memory allocated: \033[32m%zu\033[0m bytes\n", pq.allocated_memory);
  puts("");

  highlightText("Adding new element with highest priority to LIST priority queue:\n", "yellow");
  enqueue_lpq(lpq, 100, 10);
  print_lpq(lpq);
  printf("Memory allocated: \033[32m%zu\033[0m bytes\n", lpq->allocated_memory);
  puts("");

  highlightText("Adding new element with highest priority to ARRAY priority queue:\n", "yellow");
  push_priority_queue(&pq, 100, 10);
  print_priority_queue(&pq);
  printf("Memory allocated: \033[32m%zu\033[0m bytes\n", pq.allocated_memory);
  puts("");

  highlightText("Adding new element with similar priority to LIST priority queue:\n", "blue");
  enqueue_lpq(lpq, 777, 2);
  print_lpq(lpq);
  printf("Memory allocated: \033[32m%zu\033[0m bytes\n", lpq->allocated_memory);
  puts("");

  highlightText("Adding new element with similar priority to ARRAY priority queue:\n", "blue");
  push_priority_queue(&pq, 777, 2);
  print_priority_queue(&pq);
  printf("Memory allocated: \033[32m%zu\033[0m bytes\n", pq.allocated_memory);
  puts("");

  highlightText("Pop 4 elements from LIST priority queue:\n", "yellow");
  dequeue_lpq(lpq);
  dequeue_lpq(lpq);
  dequeue_lpq(lpq);
  dequeue_lpq(lpq);
  print_lpq(lpq);
  printf("Memory allocated: \033[32m%zu\033[0m bytes\n", lpq->allocated_memory);
  puts("");

  highlightText("Pop 4 elements from ARRAY priority queue:\n", "yellow");
  pop_priority_queue(&pq);
  pop_priority_queue(&pq);
  pop_priority_queue(&pq);
  pop_priority_queue(&pq);
  print_priority_queue(&pq);
  printf("Memory allocated: \033[32m%zu\033[0m bytes\n", pq.allocated_memory);
  puts("");

  destroy_lpq(lpq);
  destroy_priority_queue(&pq);
}