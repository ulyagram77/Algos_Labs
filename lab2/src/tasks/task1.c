#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "general_utils.h"

double f(double x) { return x * x * x - 2 * x * x - 3 * x + 10; }

double recursiveBisection(double a, double b, double epsilon) {
  double mid = (a + b) / 2;

  if (fabs(f(mid)) <= epsilon) {
    return mid;
  }

  if (f(a) * f(b) >= 0) {
    printf("The function has no root on that interval [%f, %f]\n", a, b);
    exit(0);
  }

  if ((b - a) < epsilon) {
    return mid;
  } else if (f(mid) * f(a) < 0) {
    return recursiveBisection(a, mid,
                              epsilon); // шукаємо корінь у проміжку [a, mid]
  } else {
    return recursiveBisection(mid, b,
                              epsilon); // шукаємо корінь у проміжку [mid, b]
  }
}

double iterationBisection(double a, double b, double epsilon) {
  double mid = 0;

  if (f(a) * f(b) >= 0) {
    printf("The function has no root on that interval [%f, %f]\n", a, b);
    exit(0);
  }

  while ((b - a) >= epsilon) {
    mid = (a + b) / 2;

    // Якщо середня точка є коренем
    if (fabs(f(mid)) <= epsilon) {
      break;
    }

    // Вибір інтервалу для подальшого пошуку
    if (f(mid) * f(a) < 0) {
      b = mid;
    } else {
      a = mid;
    }
  }

  return mid;
}

void iterationBisectionTest(double a, double b, double epsilon,
                            int test_iterations) {
  double f_root = 0;
  double speed_time = 0, avg_speed_time = 0, avg_test = 0;
  clock_t start, end;

  for (size_t i = 0; i < test_iterations; i++) {
    start = clock();
    f_root = iterationBisection(a, b, epsilon);
    // printf("The root of the equation on the interval \033[33m[%.2f, "
    //        "%.2f]\033[0m: %.2f\n",
    //        a, b, f_root);
    end = clock();
    speed_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    // printf("Function execution time: \033[32m%.3f\033[0m ms.\n\n",
    // speed_time);
    avg_speed_time += speed_time;
  }

  avg_test = avg_speed_time / test_iterations;

  printf("AVERAGE EXECUTION TIME USING \033[34m%d\033[0m CALLS OF"
         "\033[34m ITERATIVE \033[0m"
         "METHOD IS: "
         "\033[32m%.3f\033[0m milliseconds.\n\n\n\n",
         test_iterations, avg_test);
}

void recursiveBisectionTest(double a, double b, double epsilon,
                            int test_iterations) {
  double f_root = 0;
  double speed_time = 0, avg_speed_time = 0, avg_test = 0;
  clock_t start, end;

  for (size_t i = 0; i < test_iterations; i++) {
    start = clock();
    f_root = recursiveBisection(a, b, epsilon);
    // printf("The root of the equation on the interval \033[33m[%.2f, "
    //        "%.2f]\033[0m: %.2f\n",
    //        a, b, f_root);
    end = clock();
    speed_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    // printf("Function execution time: \033[32m%.3f\033[0m ms.\n\n",
    // speed_time);
    avg_speed_time += speed_time;
  }

  avg_test = avg_speed_time / test_iterations;

  printf("AVERAGE EXECUTION TIME USING \033[34m%d\033[0m CALLS OF"
         "\033[34m ITERATIVE \033[0m"
         "METHOD IS: "
         "\033[32m%.3f\033[0m milliseconds.\n\n\n\n",
         test_iterations, avg_test);
}

void task1() {
  double a = -70, b = 70, epsilon = 0.0001, test_iterations = 3000;

  highlightText("Iterative bisection algorythm:", "blue");
  iterationBisectionTest(a, b, epsilon, test_iterations);

  highlightText("Recursive bisection algorythm:", "blue");
  recursiveBisectionTest(a, b, epsilon, test_iterations);
}