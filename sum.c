// gcc -fPIC -shared -o libsum.so sum.c

long double our_function(int num_numbers, long double *numbers) {
    int i;
    long double sum = 0;
    for (i = 0; i < num_numbers; i++) {
        sum += numbers[i];
    }
    return sum;
}
