#include <stdio.h>


typedef char Date[11];
typedef struct  
{
    char  name[60];
    Date  birthday;
    int   status;      // e.g. 1 (≡ full time)
    float salary;
} WorkerT;

int main(void) {
    WorkerT w;  WorkerT *wp;
    wp = &w;
    // a problem ...
    // *wp.salary = 125000.00;
    // does not have the same effect as
    w.salary = 125000.00;
    // because it is interpreted as
    // *(wp.salary) = 125000.00;

    // to achieve the correct effect, we need
    (*wp).salary = 125111.00;
    // a simpler alternative is normally used in C
    // wp->salary = 125000.00;
    printf("%f\n", w.salary);
    return 0;
}