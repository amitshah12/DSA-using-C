#include <stdio.h>
#include <stdlib.h>
// linked list implementation

// Define the node structure
typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    node *head, *second, *temp;
    head = 0;
    int choice = 1;
    int count = 0;

    while (choice)
    {
        second = (struct node *)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &second->data);
        second->next = 0;
        if (head == 0)
        {
            head = temp = second;
        }
        else
        {
            temp->next = second;
            temp = second;
        }

        printf("do you want to continue(0,1)?");
        scanf("%d", &choice);
    }

    //Traversing lined list
    temp = head;
    while (temp != 0)
    {
        printf("%d->", temp->data);
        temp = temp->next;
        count++;
    }

    printf("\n");
    printf("total no. of node: %d", count);

    return 0;
}