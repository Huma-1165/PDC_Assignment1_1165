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
int main() {
    int arr[N];
    srand(42);
    initializeArray(arr);

    double start = omp_get_wtime();
    long long sum = parallelSumStatic(arr);
    double end = omp_get_wtime();

    printf("Parallel Sum (Static Scheduling): %lld\n", sum);
    printf("Execution Time: %f seconds\n", end - start);

    return 0;
}
// In this code, we have used the OpenMP directive #pragma omp parallel for to parallelize the sum calculation. The schedule(static) clause specifies that the loop iterations should be divided into chunks of equal size and assigned to threads in a round-robin fashion. The reduction(+:sum) clause ensures that the partial sums computed by each thread are combined into a single final sum.