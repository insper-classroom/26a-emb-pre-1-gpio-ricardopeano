#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMENTS 5

static int multiplyNumbers(int x, int y) {
    return x * y;
}

int main(void) {
    int a = 0;
    int b = 5; //uninitvar, legacyUninitvar
    int result = multiplyNumbers(a, b);

    int arr[NUM_ELEMENTS];
    for(int i = 0; i < NUM_ELEMENTS; i++) { //arrayIndexOutOfBounds
        arr[i] = i;
    }

    int sum = result;
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        sum += arr[i];
    }
    printf("%d\n", sum);
    
    return 0;
}