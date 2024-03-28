#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} IndexedValue;

// Function to compare two IndexedValue structs
int compare(const void *a, const void *b) {
    IndexedValue *indexedA = (IndexedValue *)a;
    IndexedValue *indexedB = (IndexedValue *)b;
    
    // Compare values
    if (indexedA->value < indexedB->value)
        return -1;
    else if (indexedA->value > indexedB->value)
        return 1;
    else
        return 0;
}

// Function to sort array with indices
void sortArrayWithIndices(int arr[], int n) {
    IndexedValue *indexedArr = (IndexedValue *)malloc(n * sizeof(IndexedValue));
    if (indexedArr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Populate indexed array
    for (int i = 0; i < n; i++) {
        indexedArr[i].value = arr[i];
        indexedArr[i].index = i;
    }

    // Sort indexed array
    qsort(indexedArr, n, sizeof(IndexedValue), compare);

    // Output sorted array with indices
    printf("Sorted Array with Indices:\n");
    for (int i = 0; i < n; i++) {
        printf("Value: %d, Index: %d\n", indexedArr[i].value, indexedArr[i].index);
    }

    // Free memory
    free(indexedArr);
}

int main() {
    int arr[] = {5, 2, 5, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArrayWithIndices(arr, n);

    return 0;
}
