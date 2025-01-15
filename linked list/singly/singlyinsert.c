#include <stdio.h>
#include <stdlib.h>
//insersion of note at begining, between node, at end & after a node

//traversal
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

void createSLL(Node **head, int n)
{
	int i;
	Node *temp, *newNode;
	temp = *head;
	for(i=0; i<n; ++i)
	{
		newNode = malloc(sizeof(Node));
		printf("Enter value for %d node: ", i+1);
		scanf("%d",&newNode->data);
		newNode->next = NULL;
		temp->next = newNode;
		temp = temp->next;
	}
}

// Case-1: insertng node at beginning
struct Node *insertbig(struct Node *head, int data){
    struct Node *ptr =(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
    
}

// Case-2: insert at between node
struct Node *insertbetween(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i =0;
    while (i != index-1){
        p=p->next;
        i++;
    }
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
        return head;
}

// Case-3 insert at end
struct Node *insertend(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    
    while(p->next!=NULL){
        p = p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
    
}

//Case-4 insert after a node
struct Node *insertAfternode(struct Node *head, struct Node *prevnode, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    
    return head;
    
}

int main()
{
    int n;
	Node *head;
	head = malloc(sizeof(Node));
	printf("Enter number of nodes in the linked list: ");
	scanf("%d", &n);
// 	head->data = n;
// 	head->next = NULL;
    createSLL(&head, n);
    printf("linked list before insertion\n");
    linkedlisttraversal(head);
    printf("\n");
    //head=insertbig(head, 56);
    //head = insertbetween(head, 56, 2);
    head = insertend(head, 56);
    //head = insertAfternode(head, second,45);
    printf("linked list after insertion\n");
    linkedlisttraversal(head);
    
    return 0;
}