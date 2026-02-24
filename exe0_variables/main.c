#include "stdio.h"

static void foo(int *a) {
    (*a) = (*a) + 1; // acessa variavel global
}

int main(void) {
    int a = 0; // var global
    int b = 0; // var global
    while (1) {
        foo(&a);
        
        if (a > 5) {
            b = 1;
        }
        (void)b;
    }
    return 0;
}