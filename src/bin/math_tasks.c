#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

int main() {
    double a = 123;

    double f1 = cos(a) + sin(a) + cos(3 * a) + sin(3 * a);
    double f2 = 2 * sqrt(2) * cos(a) * sin(M_PI / 4 + 2 * a);

    printf("f1=%f\n", f1);
    printf("f2=%f\n", f2);
}
