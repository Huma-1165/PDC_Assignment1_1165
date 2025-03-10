#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000  // Array size

void initializeArray(int arr[]) {
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100;  // Random numbers between 0-99
}