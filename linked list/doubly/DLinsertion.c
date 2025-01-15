#include <stdio.h>
#include <stdlib.h>

//implementation of Doubly linkedlist and insertion of node in different position
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;

// Global pointers for head and tail
node *head = NULL, *tail = NULL;

//insert at begining
void insertAtBeg(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    //newnode->next=0;  //not compulsary to write this
    
    head->prev = newnode;
    newnode->next = head;
    head=newnode;
    
    printf("Node inserted at the beginning.\n");
}



//***
//insert at end
void insertAtEnd() {
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    //**
    // newNode->next = NULL;
    // newNode->prev = tail;

    // if (tail != NULL) {
    //     tail->next = newNode;
    // } else {
    //     head = newNode; // If the list was empty
    // }
    // tail = newNode;
    //**
    
    newnode->prev=NULL;
    newnode->next=NULL;
    
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;

    printf("Node inserted at the end.\n");
}
//***

//insert at position
void insertAtPos(){
    int pos;
    int i=1;
    printf("Enter Position:");
    scanf("%d", &pos);
    
    if(pos<1){// || pos>length
        printf("Invalid position");
    } else if (pos==1){
        insertAtBeg();
        return;
    } else {
        struct node *newnode, *temp;
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        
        temp = head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev = newnode;
        
    }
    printf("Node inserted at position %d.\n", pos);
}

//insert after position
void insertAfterPos(){
    int pos;
    int i=1;
    printf("Enter Position:");
    scanf("%d", &pos);
    
    if(pos<1){//pos>length
        printf("Invalid position");
    } else{
        struct node *newnode, *temp;
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        
        temp = head;
        while(i<pos){ //after position node
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev = newnode;
        
    }
}

struct node *head,*temp;
void create(){
    //head = 0;
    int choice = 1;
    
    while(choice){
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        
        if(head==0){
            // head=temp=newnode;
            head=tail=newnode;
        }
        else
        {
            // temp->next = newnode;
            // newnode->prev = temp;
            // temp=newnode;
            
            tail->next = newnode;
            newnode->prev = tail;
            tail=newnode;
        }
        printf("Do you wnat to insert more data?(0,1)");
        scanf("%d",&choice);
    }
}



void display(){
    int count = 0;
    temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
        count++;
    }
    printf("NULL\n");
    printf("no of data: %d\n",count);
}


int main() {
    int choice;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Insert After Position\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insertAtBeg();
                break;
            case 4:
                insertAtEnd();
                break;
            case 5:
                insertAtPos();
                break;
            case 6:
                insertAfterPos();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    

    return 0;
}
