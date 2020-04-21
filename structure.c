/*
    Structure of a C program
*/

#include <stdio.h>  // preprocessor directive

#define NUM_ITERATIONS 5 // identifier definition

void message(void); // declaration


// definition of the main function
int main() {
    int count=0; // variable declaration and initilization

    while (count < NUM_ITERATIONS){
        message();
        count++;
    }
    return 0;
}

// definition of function `message`
void message(void) {
    printf("Hello World\n");
}
