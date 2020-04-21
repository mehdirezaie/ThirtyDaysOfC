/*
    Credit : hackerrank.com

    * Task 
    To complete this challenge, you must save a line of 
    input from stdin to a variable, print Hello, World. 
    on a single line, and finally print the value of your
    variable on a second line.

    * Input Format
    A single line of text denoting `input_string`
   (the variable whose contents must be printed).
    
    * Output Format
    Print Hello, World. on the first line, 
    and the contents of `input_string` on the second line.

    * Sample Input
    Welcome to 30 Days of Code!

    * Sample Output
    Hello, World. 
    Welcome to 30 Days of Code!


    Edited by:
    Mehdi Rezaie, medirz90@icloud.com 
    Dec 30, 2019
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input_string[105]; 
    
    scanf("%[^\n]", input_string); 
    
    printf("Hello, World.\n");
    printf("%s\n", input_string); 
    return 0;
}
