#include <stdio.h>
#include <stdlib.h>
//by giving own node

//traversal
struct Node
{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//insertng node at beginning
struct Node *insertbig(struct Node *head, int data){
    struct Node *ptr =(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
    
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

    linkedlisttraversal(head);
    printf("\n");
    head=insertbig(head, 56);
    linkedlisttraversal(head);
    
    return 0;
}