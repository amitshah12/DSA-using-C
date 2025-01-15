#include <stdio.h>
#include <stdlib.h>
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



void getlength(struct Node *head){
    int count =0;
    struct Node *temp;
    temp = head;
    while(temp != 0){
        count++;
        temp = temp -> next;
    }
    printf("length is: %d", count);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // terminate the list at the third node
    third->data = 66;
    third->next = NULL;

    
    printf("linked list before deletion:\n");
    linkedlisttraversal(head);
    
    
    printf("\n");
    getlength(head);
    return 0;
}