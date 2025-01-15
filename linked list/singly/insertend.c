#include <stdio.h>
#include <stdlib.h>

//traversal
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//insert at end
struct Node *insertend(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    
    while(p->next!=NULL){
        p = p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
    
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    // allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth =(struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // terminate the list at the third node
    third->data = 66;
    third->next = forth;
    
    forth->data= 77;
    forth->next = NULL;
    
    printf("linked list before insertion\n");
    linkedlisttraversal(head);
    printf("\n");
    
    head = insertend(head, 56);
    printf("linked list after insertion\n");
    linkedlisttraversal(head);
    
    return 0;
}