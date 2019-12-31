/*
    The variables i, d, and s are already declared and initialized for you. 
    You must:
    
    Declare  variables: one of type int, one of type double, and one of type String.
    Read  lines of input from stdin (according to the sequence 
    given in the Input Format section below) and initialize your variables.
    Use the  operator to perform the following operations: 
    Print the sum of  plus your int variable on a new line.
    Print the sum of  plus your double variable to a scale of one decimal place on a new line.
    Concatenate  with the string you read as input and print the result on a new line.

    Dec 31, 2019
    MR
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    int i2;
    double d2;
    char stot[200],s2[100];

    scanf("%d\n", &i2);
    scanf("%lf\n", &d2);
    scanf("%[^\n]", &s2[0]);

    strcpy(stot, s);
    strcat(stot, s2);
    
    printf("%d\n", i+i2);
    printf("%.1f\n", d+d2);
    printf("%s\n", stot);
    return 0;
}
