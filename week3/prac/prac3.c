#include <stdio.h>
#include <string.h>
#include "stdbool.h"
#include <stdlib.h>


bool isHeterogram(char new_str[]) {
    bool himo = false;
    if (strlen(new_str) == 0) {
        return true;
    }
    else {
    for (int i=0; i<strlen(new_str) -1; i++){
        for (int j=i+1; j<strlen(new_str); j++){
            if (new_str[j] == new_str[i]) {
                himo = false;
                break;
            }
            else himo = true;
        }
        if (himo == false) break;
    }
    return himo;
    }
}


char *remove_space(char *str) {
    size_t l = strlen(str);
    char *new_str = malloc(l+1);
    if (new_str == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
    }

    int non_space = 0;
    for (int i=0; i<strlen(str); i++) {
        if (str[i] != ' ') {
            new_str[non_space] = str[i];
            non_space++;
        }
    }
    new_str[non_space] = '\0';
    return new_str;
}

int main(void) {
    char str[64];
    printf("Enter a word or phrase: ");
    scanf("%[^\n]%*c",str);
    char *new_str = remove_space(str);
    if (isHeterogram(new_str)) {
        printf("\"%s\" is a heterogram\n", str);
    }
    else printf("\"%s\" is not a heterogram\n", str);
    return 0;

}