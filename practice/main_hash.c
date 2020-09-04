/*
*   Example of Hash table
*
*   compile with $ gcc main.c hashtable.c -o hashtest
*   run with $./hashtest
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashtable.h"
#define N 5
#define MAXVAL 1000


int main(void){
    int i;
    Record a;

    srand(time(NULL));

    // initialize
    init();

    // Insert N random records
    for (i = 0; i < N; ++i) {
        
        // Generate new random record
        a = malloc(sizeof(*a));
        a->key   = rand() % MAXVAL;
        a->value = rand() % MAXVAL;
        
        // Don't allow duplicate keys
        if (search(a->key) != NULL) {
            --i;
            continue;
        }
        
        // Insert new record
        printf("Inserting: Key => %i, Value => %i\n", a->key, a->value);
        insert(a);
    }


    // Search and delete records for all possible keys
    for (i = 0; i < MAXVAL; ++i) {
        if ((a = search(i)) != NULL) {
            printf("")
            printf("Deleting: Key => %i, Value => %i\n", a->key, a->value);
            delete(a->key);
        }
    }
    
    return 0;
}
