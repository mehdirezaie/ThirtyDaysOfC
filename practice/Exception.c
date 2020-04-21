#include<stdio.h>
#include <stdlib.h>

int main() {
    // Converting a numeric string
    char str[10];
    int x;
    
    scanf("%[^\n]", str); 

    x = atoi(str);

    if ((x == 0) & (str!="0")){
        printf("Bad String");
    } 
    else {
        printf("%d\n", x);
    }
    return 0;
}
