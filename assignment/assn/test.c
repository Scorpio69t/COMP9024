#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <math.h>

int main(void) {
    float old_rank = 0.161458;
    double count = 4.0;
    double sink = 0.0;
    double damping = 0.85;
    sink = sink + (damping*((float) old_rank/count));
    printf("%f", sink);
}