#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 1000000  // Array size

// Function to initialize the array with random values
void initializeArray(int arr[]) {
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100;  // Random numbers between 0-99
}
// Parallel array sum computation using dynamic scheduling
long long parallelSumDynamic(int arr[]) {
    long long sum = 0;

    #pragma omp parallel for schedule(dynamic) reduction(+:sum)
    for (int i = 0; i < N; i++)
        sum += arr[i];

    return sum;
}