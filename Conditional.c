/*
    Conditional statements

*/
#include <stdio.h>

int main()
{
    int num;
    printf("enter an integer \n");
    scanf("%d", &num);
    printf("entered number: %d ", num);

    if (num > 0){
        printf("is positive!\n");
    }else if (num < 0){
        printf("is negative!\n");
    } else{
        printf("is zero!\n");
    }
    
    return 0;
}
