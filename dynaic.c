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