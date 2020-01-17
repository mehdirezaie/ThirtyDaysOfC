/*
    Given a base-10 integer, n, convert it to binary (base-2).
    Then find and print the base-10 integer denoting
    the maximum number of consecutive 1's in n's binary representation.

    Jan 16, 2020 - MR
*/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
int conseqone(int n);


int conseqone(int n){
    int i, j, nones, nonemax, binary[100];

    // transform to binary
    j =0;
    for (i=0;n>0;i++){
        binary[i] = n % 2;
        n = n / 2;
        j++;
    }

    nonemax = 1;
    nones   = 0;
    for (i=0;i<j;i++){
        if (binary[i]==1){
            nones++;
            if (nones > nonemax){
                nonemax = nones;
            }
        }
        else {
            nones=0;
        }
    }
    printf("%d", nonemax);
    return 0;
}


int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }
    conseqone(n);
    return 0;
}


char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
