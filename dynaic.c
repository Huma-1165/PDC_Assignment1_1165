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
int main() {
    int arr[N];
    srand(time(0));
    initializeArray(arr);

    // Parallel Execution with Dynamic Scheduling
    double start = omp_get_wtime();
    long long dynamicSum = parallelSumDynamic(arr);
    double end = omp_get_wtime();

    printf("Parallel Sum (Dynamic Scheduling): %lld\n", dynamicSum);
    printf("Dynamic Scheduling Execution Time: %f seconds\n", end - start);

    return 0;
}