#include <stdio.h>
#include <stdlib.h>
// starter code for Problems 4-8 of OSTEP, chapter 14
int main() {
    int *data = (int *)malloc(100 * sizeof(int));
    data[100] = 10;
    free(data[100]);
    printf("data[100]: %d\n", data[100]);
//    int *x;
//    x = (int *)malloc(10 * sizeof(int));
//    x[0] = 1;
//    x[1] = 2;
//    printf("x[1] = %d\n", x[1]);
    return 0;
}