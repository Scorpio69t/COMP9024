#include <stdio.h>
#include<stdlib.h>  


int print_int(int n) {
    while (n!=1) {
        printf("%d\n", n);
        if (n%2 == 0 ) {
            n = n/2;
        }
        else {
            n = 3*n + 1;
        }
    }
    if (n==1) {
        printf("%d\n",n);
    }
    return 0;
}

int fibo(int n) {
    int x1 = 1;
    int x2 = 1;
    int result;
    if (n==1 || n == 2) {
        return 1;
    }
    else {
        for (int i=3; i<=n; i++) {
            result = x1 + x2;
            x1 = x2;

            x2 = result;
        }
        return result;
    }
}

int main(void){
    int k;
    for (k=1; k<=10; k++) {
        printf("Fib[%d] = %d\n", k, fibo(k));
        print_int(fibo(k));
    }
    return 0;
}