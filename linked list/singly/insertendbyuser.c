#include <stdio.h>
#include <stdlib.h>
//inserting node at end by asking node form user

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

//insetion of node at end
struct node *insertatend(struct node *head, int data){
    struct node *endnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data you want to insert at end:");
    scanf("%d",&endnode->data);
    
    
    struct node *tem;
    tem=head;
    
    while(tem->next != 0){
        tem = tem->next;
    }
    tem->next=endnode;
    endnode->next=0;
    return head;
}

int main()
{
    node *head, *newnode, *temp, *endnode;
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
    head = insertatend(head, endnode);
    printf("linked list after insertion\n");
    linkedlisttraversal(head);
    
    
    return 0;
}