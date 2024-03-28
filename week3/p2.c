 #include <stdio.h>
int main(void) {
    int *ptr1, *ptr2;
    int i=10,j=20;
    ptr1 = &i;
    ptr2 = &j;

    *ptr1 = *ptr1 + *ptr2;
    ptr2 = ptr1;
    *ptr2 = 2 * (*ptr2);
    printf("Val = %d\n", *ptr1 + *ptr2);
    return 0;
}


