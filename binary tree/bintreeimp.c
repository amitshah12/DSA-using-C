#include <stdio.h>
#include <stdlib.h>
//*****implementation of Binary tree********

// Binary tree node structure
struct node{
    int data;
    struct node *left, *right;
};

// Function to create a binary tree
struct node *create(){
    int x;
    struct node *newnode;
    newnode =(struct node*)malloc(sizeof(struct node));
    printf("Enter node:(-1 for no node):");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    newnode->data=x;
    printf("Enter left child of %d\n",x);
    newnode->left = create();
    printf("Enter right child of %d\n",x);
    newnode->right = create();
    return newnode;
}

// Pre-order traversal: Root → Left → Right
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// In-order traversal: Left → Root → Right
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Post-order traversal: Left → Right → Root
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}



int main() {
    struct node *root;
    root = 0;
    // Create the binary tree
    printf("Create the binary tree:\n");
    root = create();

    // Display the binary tree using different traversal methods
    printf("\nPre-order traversal: ");
    preorder(root);

    printf("\nIn-order traversal: ");
    inorder(root);

    printf("\nPost-order traversal: ");
    postorder(root);

    return 0;
}