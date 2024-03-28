#include <stdio.h>
#include "mystrlen.h"

int main(void) {
    char s[MAXLEN];
    int len;
    printf("Enter your string:");
    scanf("%s", s);
    len = mystrlen(s);
    printf("\n%d",len);
    return 0;
}