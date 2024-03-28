#include <stdio.h>
#include "stdlib.h"
#include "assert.h"

int fibonacci(int n) {
    if (n<=1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);

}

int main(int argc, char *argv[]) {
    if (argc != 2) {
      printf("Usage: %s number\n", argv[0]);
      return 1;
   }
   int n = atoi(argv[1]);
   long long int result = fibonacci(n-1);

   printf("%llu\n", result);

   return 0;
}