#include <stdio.h>
#include <stdlib.h>
//implementation of Stack using linked list

typedef struct node{
    int data;
    struct node *next;
}node;

struct node *top=0;
void push(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&newnode->data);
    newnode->next = top;
    top = newnode;
}

void display(){
    struct node *temp;
    temp = top;
    if(top == NULL){
        printf("List is empty\n");
    } else{
        while(temp != NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}

void peek(){
    if(top == NULL){
        printf("Stack is empty\n");
    } else {
        printf("top element is: %d\n",top->data);
    }
}

void pop(){
    struct node *temp;
    temp = top;
    if(top==NULL){
        printf("Underflow\n");
    } else {
        printf("popeed item is: %d\n",top->data);
        top= top->next;
        free(temp);
    }
}

int main() {
    int ch;
    printf("1.Push\n2.Display\n3.Peek\n4.Pop\n5.Peek\n6.display\n7.Quit/exit\n");
    do
    {
        printf("enter the operation you want to perform:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            display();
            break;
        case 3:
            peek();
            break;
        case 4:
            pop();
            break;
        case 5:
            peek();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
            break;

        default:
            printf("invalid choice\n");
            break;
        }
    } while (ch != 0);
    

    return 0;
}