/*
    Code to compute the number Pi = 3.14

    Integral 4/(1+x^2) from 0 to 1 is 3.14

    gcc -shared -o pi.so -fPIC pi.c
*/
#include <stdio.h>
#include <time.h>


float pi(int num_steps);

float pi(int num_steps)
{
     double start, end, step, x, sum; int i;
     start = clock();
     step = 1.0/(double)num_steps;
     sum = 0;
     for (i=0;i<num_steps;i++)
     {
          x = (i+0.5)*step;
          sum = sum + 4.0/(1.0+x*x);
     }
     end= clock();
     return step * sum;
}

int main()
{
    float result;
    double start, end;
    start = clock();
    result = pi(10000000);
    end = clock();

    printf("Pi = %f in %f secs\n", result, (float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
