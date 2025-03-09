#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

void initializeArray(int arr[]) {
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100;
}