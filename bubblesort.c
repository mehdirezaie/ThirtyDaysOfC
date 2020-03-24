#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void swap(int *xp, int *yp);

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int main() {
    int n; 
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
    	scanf("%d",&a[a_i]);
    }
    // Write Your Code Here
    
    int swapped;
    int numberOfSwaps=0;
    for (int i = 0; i < n; i++) {     
        swapped=0;   
        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                numberOfSwaps++;
                swapped=1;
            }
        }
        
        // If no elements were swapped during a traversal, array is sorted
        if (swapped == 0) {
            break;
        }   
    }
    // print
    printf("Array is sorted in %d swaps.\n", numberOfSwaps);    
    printf("First Element: %d\n", a[0]);
    printf("Last Element: %d\n", a[n-1]);

    /*
    for (int i = 0; i<n; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    */

    return 0;
}

