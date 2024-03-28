#include <stdio.h>

int main(void){
    int a = 5;                    // line 1
    int b = 123;                  // line 2

    int *pa = &a;                 // line 4
    int *pb = &b;                 // line 5

    *pa = 6;                      // line 7
    *pb = 234;                    // line 8

    int c = *pa;                  // line 10
    *pa = *pb;                    // line 11 a = 234, b = 234, c=6
    *pb = c;                        //a=234, b=6, c=6
    pa = pb;                        //a=234, b=6, c=6, pa point to b
    *pa = 345;                    // a = 234, b=345, c=6

    printf("%d %d %d", a, b, c);

}