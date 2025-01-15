#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[N];
int top=-1;

void push(){
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if(top == N-1){
        printf("overflow");
    } else{
        top++;
        stack[top]=x;
    }
}

void pop(){
    int del;
    if(top == -1){
        printf("underflow");
    } else{
        del = stack[top];
        top--;
        printf("%d", del);
    }
}

void peek(){
    if(top == -1){
        printf("Stack is empty");
    } else {
        printf("%d",stack[top]);
    }
        
}

void display(){
    int i;
    for(i=top; i<=0; i--){
        printf("%d", stack[i]);
    }
}
int main() {
    push();
    pop();
    peek();
    display();

    return 0;
}