#include <stdio.h>
#include "stdlib.h"
#include "assert.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
      printf("Usage: %s number\n", argv[0]);
      return 1;
   }
   int n = atoi(argv[1]);
   long long int result;
   long long int *arr = malloc((n)*sizeof(long long int)); 
   if (n==1) {result=1;}
   else if (n==2) {result=1;}
   else { arr[0] = 1;
   arr[1] = 1;
   for (int i=2; i<n; i++) {
    arr[i] = arr[i-1] + arr[i-2];
   }
   result = arr[n-1];

   }
    printf("%llu\n", result);

   return 0;
}