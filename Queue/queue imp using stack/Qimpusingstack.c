#include <stdio.h>
#include <stdlib.h>

//Implementation of Queue Using Stack (array)
#define N 5
int S1[N], S2[N];
int top1 = -1, top2=-1;
int count =0;

void push1(int data){
//void push1(){
    if(top1==N-1){
        printf("Stack is full!\n");
    } else{
        top1++;
        // printf("Enter data:");
        // scanf("%d",S1[top1]);
        S1[top1]=data;
    }
}

void push2(int data){
    if(top2==N-1){
        printf("Stack is full!\n");
    } else{
        top2++;
        S2[top2]=data;
    }
}

//void enqueue(int x){
void enqueue(){
    int x;
    if(top1==N-1){
        printf("Queue is full\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d",&x);
    push1(x);
    count++;
}

int pop1(){
    return S1[top1--];
}

int pop2(){
    return S2[top2--];
}


void dequeue(){
    int a,b;
    if(top1==-1 && top2==-1){
        printf("Queue is empty");
    } else {
        for(int i=0; i<count; i++){
            a=pop1();
            push2(a);
        }
        b=pop2();
        printf("The dequeued elemnent is %d\n",b);
        count--;
        for(int i =0; i<count; i++){
            a=pop2();
            push1(a);
        }
    }
}

void display(){
    if(top1==-1 && top2==-1){
        printf("Queue is empty");
    }else{
        printf("Queue is: ");
        for(int i=0; i<=top1; i++){
            printf("%d ",S1[i]);
        }
    }
}


void peek() {
    if (top1 == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Front of the queue is: %d\n", S1[0]);
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