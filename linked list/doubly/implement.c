#include <stdio.h>
#include <stdlib.h>
//implemeniton doubly linked list

//linked list implementation
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

struct node *head;
void create(){
    head = NULL;
    struct node *temp;
    int choice = 1;
    while(choice){
        struct node *newnode =(struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode -> prev = NULL;
        newnode -> next = NULL;
        if(head == NULL){
            head=temp=newnode;
            }else{
                temp->next=newnode;
                newnode->prev=temp;
                temp=newnode;
            }
            printf("Do you want to continue(0,1)?");
            scanf("%d",&choice);
    }
}

void display(){
    struct node *temp;
    int count=0;
    temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\n");
    printf("No. of node=%d", count);
}


int main()
{
    create();
    display();
   return 0;
}