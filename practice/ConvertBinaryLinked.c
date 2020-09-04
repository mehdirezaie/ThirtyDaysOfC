/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 
 Given head which is a reference node to a singly-linked list. 
 The value of each node in the linked list is either 0 or 1. 
 The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.
 */

int getDecimalValue(struct ListNode* head){
    
    int* values= (int*) malloc(30 * sizeof(int));
    
    int i = 0;
    while (head != NULL){
        values[i] = head->val;
        head = head->next;
        i++;
    }
    
    int decimal = 0;
    for (int j=0; j < i; j++){
        decimal += values[j]*pow(2, i-j-1);
    }
    
    return decimal;
}



