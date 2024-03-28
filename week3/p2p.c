#include <stdio.h>

int main() {
    int x = 10;
    int *ptr = &x; // con trỏ ptr trỏ tới biến x
    int **ptr_to_ptr = &ptr; // con trỏ ptr_to_ptr trỏ tới con trỏ ptr

    printf("Giá trị của x: %d\n", x);
    printf("Giá trị của *ptr: %d\n", *ptr);
    printf("Giá trị của **ptr_to_ptr: %d\n", **ptr_to_ptr);

    return 0;
}
