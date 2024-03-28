#include <stdio.h>
#include "stdlib.h"

int main(int argc, char *argv[] ) {
    if (argc != 2) {
      printf("Usage: %s number\n", argv[0]);
      return 1;
   }
   char *str = argv[1];
   int len=0;
   while (str[len] != '\0') {
    len++;
   }
   for (int i=len; i>=0; i--) {
    for (int j=0; j<i; j++){
        printf("%c",str[j]);
    }
    printf("\n");
   }
}