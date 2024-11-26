#ifndef TASKS_H_INCLUDED
#define TASKS_H_INCLUDED

#include <stdio.h>
#include <time.h>

void task1();

void (*tasks[])() = {
    task1,
};

#endif