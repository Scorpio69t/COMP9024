#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_spaces(const char *s) {
    size_t len = strlen(s);
    char *new_str = malloc(len + 1); // Allocate memory for the new string
    if (new_str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (s[i] != ' ') {
            new_str[j++] = s[i];
        }
    }
    new_str[j] = '\0'; // Null-terminate the new string

    return new_str;
}

int main() {
    const char *original_str = "abc xyz";
    char *modified_str = remove_spaces(original_str); // Remove spaces
    
    printf("Original string: %s\n", original_str);
    printf("Modified string: %s\n", modified_str);
    
    free(modified_str); // Free the memory allocated for the modified string
    
    return 0;
}
