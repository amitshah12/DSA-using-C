#include <stdio.h>
#include <stdlib.h>

//Linear Queue implementation using array
#define N 5
int queue[N];
int front = -1;
int rear = -1;

//Insertion of data
void enqueue(){
    if(rear == N-1){
        printf("Overflow!\n");
    } else if(front==-1 && rear ==-1){
        
        front = rear =0;
        printf("Enter data: ");
        scanf("%d",&queue[rear]);
    } else {
        rear++;
        printf("Enter data: ");
        scanf("%d",&queue[rear]);
    }
}

//deletion of data(poped)
void dequeue(){
    if(front==-1 && rear ==-1){
        printf("Underflow!\n");
    } else if (front == rear){
        front = rear = -1;
    } else {
        printf("Dequeued element is: %d\n",queue[front]);
        front++;
    }
}

//To display output
void display(){
    if(front==-1 && rear==-1){
        printf("Underflow!\n");
    } else {
        for(int i=front; i<rear+1; i++){
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
}

//to display data present at front
void peek(){
    if(front==-1 && rear==-1){
        printf("Underflow!\n");
    } else {
        printf("The data at front is: %d",queue[front]);
        
    }
}



int main() {
    int choice;

    while (1) {
        printf("\nStacks Operations:\n");
        printf(" 1. enqueue\n 2. Dequeue\n 3. Display\n 4. Peek\n 5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
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