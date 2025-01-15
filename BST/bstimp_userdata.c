#include <stdio.h>
#include <stdlib.h>
//Implementation of Binary search tree using linked list

//Define a structure for a binary tree node
struct node {
    int data;
    struct node *left, *right;
};

//Function to create a new node with a given key
struct node* createNode(int key) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

//Function to insertBST a key into a BST
struct node* insertBST(struct node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    
    if (key < root->data) {
        root->left = insertBST(root->left, key);
    } else {
        root->right = insertBST(root->right, key);
    }
    return root;
}

//Function to perform inorder traversal of the BST
void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);  // Add space for better formatting
        inorderTraversal(root->right);
    }
}

//Function to find the node with the minimum key value in a BST
struct node* minValueNode(struct node* root) {
    struct node* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

//Function to delete a key from the BST
struct node* deleteNode(struct node* root, int key) {
    //Base case:if the tree is empty
    if (root == NULL) {
        return root;
    }

    //Recursively find and delete the key in the left or right subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        //Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        //Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
        //copy the inorder successor's key to this node
        root->data = temp->data;
        //Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

//Function to search for a key in the BST
struct node* search(struct node* root, int key) {
    //Base cases: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }
    
    //key is greater than root's key
    if (key > root->data) {
        return search(root->right, key);
    }
    //key is smaller than root's key
    return search(root->left, key);
}

// Function to free the entire BST
void freeTree(struct node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct node* root = NULL;
    int choice, key;

    do {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display In-order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insertBST(root, key);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                struct node* searchResult = search(root, key);
                if (searchResult != NULL)
                    printf("%d found in the BST.\n", key);
                else
                    printf("%d not found in the BST.\n", key);
                break;
            case 4:
                printf("In-order traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    freeTree(root);  // Free the allocated memory
    return 0;
}
