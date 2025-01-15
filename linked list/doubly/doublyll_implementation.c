#include <stdio.h>
#include <stdlib.h>


//Doubly linkded list implementation

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;

int main() {
    struct node *newnode, *head, *temp;
    head = 0;
    int choice = 1;
    int count = 0;
    
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0){
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
            
        }
        printf("Do you want to enter more data(0,1)?");
        scanf("%d", &choice);
    }
    temp=head;
    while(temp!=0){
        printf("%d->",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\n");
    printf("Total no of node:%d",count);
    

    return 0;
}