#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int)); // Cấp phát bộ nhớ động cho con trỏ ptr

    free(ptr); // Giải phóng bộ nhớ đã được cấp phát

    ptr = NULL; // Gán con trỏ ptr thành NULL sau khi giải phóng bộ nhớ

    *ptr = 10; // Ghi vào vùng nhớ đã được giải phóng , đây là hành vi không xác định

    return 0;
}
