#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//case 1: deleting node from first
// struct Node *deletefirst(struct Node *head){
//     struct Node *ptr = head;
//     head = head -> next;
//     free(ptr);
//     return head;
// }

//case 2: deleting node from end
// struct Node *ptr, *prevnode;
// struct Node *deletend(struct Node *head){
    
//     ptr=head;
//     while(ptr->next != 0){
//         prevnode = ptr;
//         ptr = ptr->next;
//     }
//     if(ptr==head){
//         head =0;
//     }else{
//         prevnode->next=0;
//     }
//     free(ptr);
//     return head;
// }

//case 3 : delete from index
struct Node *deleteatindex(struct Node *head){
    int index;
    struct Node *p=head;
    struct Node *q = head->next;
    for(int i =1; i<index-1; i++){
        p = p->next;
        q = q->next;
        
    }
    p->next = q->next;
    free(q);
    
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // terminate the list at the third node
    third->data = 66;
    third->next = NULL;

    
    printf("linked list before deletion:\n");
    linkedlisttraversal(head);
    
    printf("linked list after deletion:\n");
    //head = deletefirst(head);
    //head = deletend(head);
    head = deleteatindex(head);
    linkedlisttraversal(head);
    return 0;
}