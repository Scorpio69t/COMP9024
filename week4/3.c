#include <stdio.h>
#include "stdlib.h"
#include <assert.h>

#define SIZE 1000

int *makeArrayOfInts() {
//    int arr[SIZE];
    int *arr;
    size_t numberOfBytes;
    numberOfBytes = SIZE * sizeof(int);
    arr = malloc(numberOfBytes);
    assert(arr != NULL);

   int i;
   for (i=0; i<SIZE; i++) {
      arr[i] = i;
   }
   return arr;
}

int main(void) {
    int *arr = makeArrayOfInts();
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Don't forget to free the memory after use
    free(arr);
    return 0;

}