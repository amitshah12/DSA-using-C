#include <stdio.h>
#include<stdlib.h>
typedef struct poly{
    float coef;
    int expo;
    struct poly *next;
}poly;

struct poly* insert(struct poly* head, float co, int ex){
    struct poly *temp;
    struct poly *newp = malloc(sizeof(struct poly));
    newp->coef=co;
    newp->expo=ex;
    newp->next=NULL;

    if(head==NULL || ex > head -> expo){
        newp->next=head;
        head = newp;
    } else {
        temp = head;
        while(temp->next != NULL && temp->next->expo>ex)
        temp = temp->next;
        newp->next=temp->next;
        temp->next=newp;
    }
    return head;
}
struct poly* create(struct poly* head){
    int n,i;
    float coef;
    int expo;
    printf("enter no. of term:");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        printf("enter the coefficient for term %d: ", i+1);
        scanf("%f", &coef);
        
        printf("enter the exponent for term %d: ", i+1);
        scanf("%d", &expo);
        head = insert(head, coef, expo); 
    }
    return head;
    
}

void print(struct poly* head){
    if(head == NULL){
        printf("No polynomial\n");
    } else {
        struct poly* temp = head;
        while(temp != NULL){
            printf("(%.1fx^%d)", temp->coef,temp->expo);
            temp = temp->next;
            if(temp != NULL){
                printf("+");
            } else {
                printf("\n");
            }
        }
    }
}
int main() {
    struct poly* head=NULL;
    printf("Enter the polynomial\n");
    
    head = create(head);
    print(head);
    

    return 0;
}