#include <stdio.h>
#include <stdlib.h>
//reversing node by asking node form user

//linked list implementation
typedef struct node
{
    int data;
    struct node *next;
} node;

// linked list traversal
void linkedlisttraversal(struct node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("\n");
    printf("total no. of node: %d", count);
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

int main()
{
    struct node *head, *newnode, *temp;
    head = 0;
    int choice = 1;
    int count = 0;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("do you want to continue(0,1)?");
        scanf("%d", &choice);
    }
    temp = head;
    
    printf("linked list before insertion\n");
    linkedlisttraversal(head);
        
    printf("\n");
    head = reverse(head);
    printf("linked list after insertion\n");
    linkedlisttraversal(head);
    
    
    return 0;
}