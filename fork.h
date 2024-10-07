#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

#ifndef FORK_H
#define FORK_H

void pattern_1(int process_count);

void pattern_2(int current_process, int process_count);

// void pattern_3_wrapper(int process_count);

// void pattern_3(heap_t *heap, int current_process, int process_count);

void pattern_3(int current_process, int process_count);



#endif