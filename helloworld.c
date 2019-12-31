/*
    Credit : hackerrank.com

    Task: save a line of input from stdin to a variable, 
    print Hello, World. on a single line, and finally 
    print the value of your variable on a second line.

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
