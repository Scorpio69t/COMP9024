#include <stdio.h>
#include "IntStack.h"
#include "Stack.c"



int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    StackInit();
    while (n>0) {
        int r = n%2;
        StackPush(r);
        n=n/2;
    }
    while (!StackIsEmpty()) {
    int ch = StackPop();
    printf("%d", ch); // Output: C B A
}
}