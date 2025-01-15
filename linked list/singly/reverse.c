#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;


void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *reverse(struct node *head){
    struct node *prevnode, *curnode, *nextnode;
    prevnode = 0;
    curnode = nextnode = head;
    while(nextnode != 0){
        nextnode = nextnode -> next;
        curnode -> next = prevnode;
        prevnode = curnode;
        curnode = nextnode;
    }
    head = prevnode;
}
int main() {
    struct node *head;
    struct node *second;
    struct node *third;

    // allocate memory for nodes in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // terminate the list at the third node
    third->data = 66;
    third->next = NULL;

    
    printf("linked list before reverse:\n");
    linkedlisttraversal(head);
    
    printf("linked list after reverse:\n");
    //head = deletefirst(head);
    //head = deletend(head);
    head = reverse(head);
    linkedlisttraversal(head);

    return 0;
}