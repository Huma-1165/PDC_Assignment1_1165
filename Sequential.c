#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000  // Array size

void initializeArray(int arr[]) {
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100;  // Random numbers between 0-99
}
long long sequentialSum(int arr[]) {
    long long sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    return sum;
}
int main() {
    int arr[N];
    srand(time(0));
    initializeArray(arr);

    clock_t start = clock();
    long long sum = sequentialSum(arr);
    clock_t end = clock();

    printf("Sequential Sum: %lld\n", sum);
    printf("Execution Time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
 
 //Parallel Sum using OpenMP 
 //OpenMP is a popular API for parallel programming in C, C++, and Fortran. It provides a set of compiler directives, library routines, and environment variables that can be used to specify shared-memory parallelism. 
 //The following code demonstrates how to parallelize the sum calculation using OpenMP.