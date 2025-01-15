#include <stdio.h>
#include<stdlib.h>


//Stack implementation using Array
#define size 5
int stack[size];
int top = -1;


int isFull(){
    return top == size - 1;
}

int isEmpty(){
    return top == -1;
}

//to push data in stack
void push(){
    int x;
    if(isFull()){
        printf("Stack is Full!\n");
    } else {
        printf("Enter data: ");
        scanf("%d", &x);
        top = top+1;
        stack[top]=x;
    }
}

//to pop(delete) data form stack
void pop(){
    int item;
    if(isEmpty()){
        printf("Stack is empty\n");
    }else{
        item = stack[top];
        top = top-1;
        printf("Poped item is:%d", item);
    }
}

//To display top element in the stack
void peek(){
    if(isEmpty()){
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d", stack[top]);
    }
}

//To display all the element in stack
void display(){
    if (isEmpty()) {
        printf("Stack is Empty!\n");
    } else {
        printf("Stack elements: ");
        for(int i=top; i>=0; i--){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}



int main() {
    int choice;

    while (1) {
        printf("\nStacks Operations:\n");
        printf(" 1. Push\n 2. Display\n 3. Pop\n 4. Peek\n 5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                display();
                break;
            case 3:
                pop();
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