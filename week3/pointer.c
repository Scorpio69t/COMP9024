#include <stdio.h>

int main(void) {
    int *p;
    int a[5];
    int x = 10;

    p = &x;
    *p = 20;
    printf("%d\n",x);
    return 0;
}