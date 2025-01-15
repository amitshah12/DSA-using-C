// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

//Circular Queue implementation using Arrays
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(){
    if(front == -1 && rear == -1){
        front = rear = 0;
        printf("Enter data: ");
        scanf("%d",&queue[rear]);
        //queue[rear] =x;
    } else if (((rear+1)%N)==front){
        printf("Queue is full!\n");
    } else {
        rear=(rear+1)%N;
        printf("Enter data: ");
        scanf("%d",&queue[rear]);
        //queue[rear]=x;
    }
}


void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
    } else if(front == rear){
        printf("The dequeued element is: %d", queue[front]);
        front=rear=-1;
    } else {
        printf("The dequeued element is: %d", queue[front]);
        front=(front+1)%N;
    }
}

void display(){
    int i =front;
    if(front==-1 && rear == -1){
        printf("Queue is empty!\n");
    } else {
        printf("Queue element is: ");
        while( i != rear){
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d", queue[rear]);
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
    } else {
        printf("The peek value is %d", queue[front]);
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