// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
//deque: double ended que
#define N 5
int deque[N];
int front = -1, Rear=-1;

void enqueuefront(int x){
    if((front==0 && Rear==N-1)||(front== Rear+1)){
        printf("Queue is full\n");
    } else if(front==-1 && Rear==-1){
        front=Rear=0;
        deque[front]=x;
    } else if(front==0){
        front=N-1;
        deque[front]=x;
    } else {
        front--;
        deque[front]=x;
    }
}

void enqueuerear(int x){
    if((front==0 && Rear==N-1)|| (front==Rear+1)){
        printf("queue is full\n");
    } else if(front==-1 & Rear==-1){
        front=Rear=0;
        deque[Rear]=x;
    } else if(Rear==N-1){
        Rear=0;
        deque[Rear]=x;
    } else {
        Rear++;
        deque[Rear]=x;
    }
}

void display(){
    int i=front;
    while(i != Rear){
        printf("%d",deque[i]);
        i=(i+1)%N;
    }
    printf("%d",deque[Rear]);
}

// void getfront(){
//     printf("%d", deque[front])
// }

void dequeuefront(){
    if(front==-1 && Rear==-1){
        printf("queue is empty\n");
    } else if(front==Rear){
        front=Rear=-1;
    } else if(front==N-1){
        printf("the dequeu value is: %d", deque[front]);
        front++;
    }
}

void dequeuerear(){
    if(front==-1 && Rear==-1){
        printf("queue is empty\n");
    } else if(front=Rear){
        front=Rear-1;
    } else if(Rear==0){
        printf("the deque element is:%d", deque[Rear]);
        Rear=N-1;
    } else {
        printf("%d", deque[Rear]);
        Rear--;
    }
}
int main() {
    // Write C code here
    printf("Hello world");

    return 0;
}