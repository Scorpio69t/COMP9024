#include "mystrlen.h"
#include <stdio.h>
int mystrlen(char *s) {
    int i=0;
    while (s[i] != '\0') {
        i++;
    }
    if (s[i] == '\0') return i;
    else return MAXLEN;
}

int main(void) {
    char s[10] = "qowejoqiw";
    int l = mystrlen(s);
    printf("%d",l);
}