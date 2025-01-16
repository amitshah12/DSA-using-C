#include <stdio.h>
#include <stdlib.h>


//Circular Queue implementation using Linkedlist
typedef struct node{
    int data;
    struct node *next;
}node;

struct node *front = 0;
struct node *rear = 0;

//Insertion of node
void enqueue(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    
    if(front==0 && rear==0){
        front=rear=newnode;
        rear->next=front;
    } else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

//to delete node
void dequeue(){
    struct node *temp;
    temp=front;
    if(front==0 && rear==0){
        printf("Queue is empty!\n");
    } else if(front==rear){
        printf("The dequeued element is: %d\n",temp->data);
        front=rear=NULL;
        free(temp);
    } else {
        printf("The dequeued element is: %d\n",temp->data);
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

//to return front element as output
void peek(){
    if(front==0 && rear==0){
        printf("Queue is empty!\n");
    } else {
        printf("The peek element is: %d",front->data);
    }
}

//Fuction to display output
void display(){
    struct node *temp;
    temp = front;
    if(front==0 && rear==0){
        printf("Queue is empty!\n");
    } else {
        while(temp->next!=front){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nStacks Operations:\n");
        printf(" 1. enqueue\n 2. Display\n 3. Dequeue\n 4. Peek\n 5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}