#include <stdio.h>
#include "string.h"
#include "stdbool.h"
#include <ctype.h>
int main() {
    char n[100];
    bool isNumeric = true;
    scanf("%99s", n);
    printf("n is %s", n);
    if (strlen(n) == 0 ) isNumeric = false;
    else {
    for (int i = 0; n[i] != '\0'; i++) {
        if (!isdigit(n[i])) {
            isNumeric = false;
            break;
        }
    }
    if (isNumeric) {
        printf("Numeric input detected: %s\n", n);
    } else {
        printf("Non-numeric input detected.\n");
    }
    }
    return 0;
}