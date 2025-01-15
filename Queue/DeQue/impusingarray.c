// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

//implementation of Deque using array
#define N 5
int deque[N];
int F = -1, R =-1;//F=front & R=Rear

void enqueueFront(int x){
    printf("Enter Data: ");
    if((F ==0 && R ==N-1) || (F==R+1)){
        printf("Queue is full\n");
    } else if (F==-1 && R==-1){ //Initial case i.e queue is empty so we can insert
        F=R=0;
        scanf("%d", &deque[F]);
        //deque[F]=x;
    } else if (F==0){
        F=N-1;
        scanf("%d", &deque[F]);
        //deque[F]=x;
    } else{
        F--;
        //deque[F]=x;
        scanf("%d", &deque[F]);
    }
}

void enqueueRear(int x){
    printf("Enter Data: ");
    if((F==0 && R==N-1) || (F=R+1)){
        printf("Queue is full\n");
    } else if (F==-1 && R==-1){
        F=R=0;
        //deque[R]=x;
        scanf("%d", &deque[R]);
    } else if (R==N-1){
        R=0;
        //deque[R]=x;
        scanf("%d", &deque[R]);
    } else {
        R++;
        // deque[R]=x;
        scanf("%d", &deque[R]);
    }
}


void display(){
    int i=F;
    while(i!=R){
        printf("%d ",deque[i]);
        i=(i+1)%N;
    }
    printf("%d ", deque[R]);
}

void getFront(){
    if(F==-1 && R==-1){
        printf("Queue is empty!\n");
    } else {
        printf("The front value is: %d",deque[F]);
    }
}

void getRear(){
    if(F==-1 && R==-1){
        printf("Queue is empty\n");
    } else {
        printf("The rear value is %d", deque[R]);
    }
}


void dequeFront(){
    if(F==-1 && R==-1){
        printf("Queue is empty\n");
    } else if(F==R){
        printf("The dequed element is %d",deque[F]);
        F=R=-1;
    } else if(F==N-1){
        printf("The dequed element is %d",deque[F]);
        F=0;
    } else {
        printf("The dequed element is %d",deque[F]);
        F++;
    }
}

void dequeRear(){
    if(F==-1 && R==-1){
        printf("Queue is empty\n");
    } else if(F==R){
        printf("The dequed element is %d",deque[F]);
        F=R=-1;
    } else if(R==0){
        printf("The dequed element is %d",deque[R]);
        R=N-1;
    } else {
        printf("The dequed element is %d",deque[R]);
        R--;
    }
}
int main() {
    int choice;

    while (1) {
        printf("\nStacks Operations:\n");
        printf(" 1. EnqueueFront\n 2. EnqueueRear\n 3. Display\n 4. DequeFront\n 5. DeQueRear\n 6.GetFront\n 7.GetRear\n ");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueueFront(6);
                break;
            case 2:
                enqueueRear(7);
                break;
            case 3:
                display();
                break;
            case 4:
                dequeFront();
                break;
            case 5:
                dequeRear();
                break;
            case 6:
                getFront();
                break;
            case 7:
                getRear();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}