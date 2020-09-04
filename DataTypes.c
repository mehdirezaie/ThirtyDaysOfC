/*
    Data types

    Real: float, double, long double
    Integral: int, long int or long, long long 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // real types
    float x = 10.0;
    double d = 10.0;
    long double ld = 10.0;
    printf("size of float %f = %ld bytes\n", x, sizeof(x));
    printf("size of double %lf = %ld bytes\n", d, sizeof(d));
    printf("size of long double %Lf = %ld bytes\n", ld, sizeof(ld));

    // integral types
    int i = 10;
    unsigned int ui = 10;
    long int li = 10;
    long long int ll = 10LL;
    printf("size of int %d = %ld bytes\n", i, sizeof(i));
    printf("size of unsigned int %u = %ld bytes\n", ui, sizeof(ui));
    printf("size of long int %ld = %ld bytes\n", li, sizeof(li));
    printf("size of long long %lld = %ld bytes\n", ll, sizeof(ll));


    // character types
    char c[]="Hello";
    printf("%s\n", c);

    return 0;
}
