#include <stdio.h>
#include <stdlib.h>

//Linear Queue implementation using Linked list
typedef struct node{
    int data; 
    struct node *next;
}node;

struct node *front = 0;
struct node *rear = 0;

//Insertion of data
void enqueue(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(front == NULL && rear == NULL){
        front=rear=newnode;
    } else {
        rear->next=newnode;
        rear=newnode;
    }
}


//To display the data in queue
void display(){
    struct node *temp;
    if(front == NULL && rear == NULL){
        printf("queue is empty!\n");
    } else {
        temp=front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

//To delete node from queue
void dequeue(){
    struct node *temp;
    temp = front;
    if(front == NULL && rear == NULL){
        printf("queue is empty!\n");
    } else {
        temp=front;
        printf("The dequeued element is: %d",front->data);
        front=front->next;
        free(temp);
    }
}

//To find top element of queue
void peek(){
    if(front == NULL && rear== NULL){
        printf("queue is empty!\n");
    } else {
        printf("The peek element is %d",front->data);
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