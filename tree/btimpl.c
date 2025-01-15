#include <stdio.h>
#include <stdlib.h>

//Binary Tree traversal | Preorder, Inorder, Postorder
typedef struct node{
    int data;
    struct node *left, *right;
}node;

// Function to create a binary tree
struct node* create(){
    int x;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data(-1 for no node): ");
    scanf("%d", &x);
    if(x == -1){
        return 0;
    }
    newnode->data=x;
    printf("enter left child of %d",x);
    newnode->left=create();
    printf("enter right child of %d",x);
    newnode->right=create();
    return newnode;
}

// Function to perform pre-order traversal
void preOrder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Function to perform in-order traversal
void inOrder(struct node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

// Function to perform post-order traversal
void postOrder(struct node *root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}


int main() {
    struct node *root;  
    root=NULL;
    root=create();
    
    printf("pre-order: ");
    preOrder(root);
    printf("\nIn-order: ");
    inOrder(root);
    printf("\npost-order: ");
    postOrder(root);

    return 0;
}
