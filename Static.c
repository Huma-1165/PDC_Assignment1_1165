#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

void initializeArray(int arr[]) {
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100;
}
long long parallelSumStatic(int arr[]) {
    long long sum = 0;
    
    #pragma omp parallel for schedule(static) reduction(+:sum)
    for (int i = 0; i < N; i++)
        sum += arr[i];

    return sum;
}