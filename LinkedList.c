#include <stdlib.h>
#include <stdio.h>	
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node * insert(Node *head,int data){
    Node *current_node = head;
    Node *new_node;

    new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next= NULL;

    while ( current_node!=NULL && current_node->next!=NULL){
        current_node = current_node->next;
    }
    if (current_node != NULL)
        current_node->next = new_node;
    else
        head = new_node;
    return head;
}

void display(Node *head)
{
	Node *start=head;
	while(start)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
int main()
{
	int T,data;
    scanf("%d",&T);
    Node *head=NULL;	
    while(T-->0){
        scanf("%d",&data);
        head=insert(head,data);
    }
  display(head);
		
}
