#include <stdio.h>
#include <stdlib.h>

#include "general_utils.h"
#include "sparse_table.h"

#define N 5

void print_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {
        printf("\033[33m%d\033[0m ", matrix[i][j]);
      } else {
        printf("%d ", matrix[i][j]);
      }
    }
    printf("\n");
  }
}

void free_matrix(int **matrix) {
  for (int i = 0; i < N; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void fill_matrix(int **matrix) {
  for (int i = 0; i < N; i++) {
    matrix[i] = (int *)malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
      matrix[i][j] = generateRandomInt(10, 80);
      if (i % 2 == 0 && j % 2 == 0) {
        matrix[i][j] = 0;
      }
    }
  }
}

void task1() {
  int **matrix = (int **)malloc(N * sizeof(int *));
  clock_t start_time, end_time;
  double access_time;

  highlightText("ORIGINAL MATRIX", "blue");

  printf("\n");
  fill_matrix(matrix);
  print_matrix(matrix, N, N);
  printf("\n");

  start_time = clock();
  printf("Access element at \033[33m(3, 1)\033[0m: %d\n", matrix[3][1]);
  printf("Access element at \033[33m(0, 0)\033[0m: %d\n", matrix[0][0]);
  end_time = clock();
  access_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("\nTime taken to access elements of matrix: \033[32m%f\033[0m ms\n",
         access_time);
  printf("\n\n\n\n");

  highlightText("ORIGINAL MATRIX CONVERTED TO SPARSE MATRIX", "blue");
  printf("\n");

  CSRMatrix csr = create(matrix, N, N);
  print(csr, N, N);
  printf("\n");

  start_time = clock();
  printf("Access element at \033[33m(3, 1)\033[0m: %d\n",
         get_element(&csr, 3, 1));
  printf("Access element at \033[33m(0, 0)\033[0m: %d\n",
         get_element(&csr, 0, 0));
  end_time = clock();
  access_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf(
      "\nTime taken to access elements of CSR matrix: \033[32m%f\033[0m ms\n",
      access_time);

  free_matrix(matrix);
  destroy(&csr);
}