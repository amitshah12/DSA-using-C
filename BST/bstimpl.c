#include <stdio.h>
#include <stdlib.h>

//binary search tree complete by giving own data

// Define a structure for a binary tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node with a given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into a BST
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, create a new node
    if (root == NULL)
        return createNode(key);

    // Otherwise, recursively insert into the appropriate subtree
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Function to perform in-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to find the node with the minimum key value in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a key from the BST
struct Node* deleteNode(struct Node* root, int key) {
    // Base case: If the tree is empty
    if (root == NULL)
        return root;

    // Recursively find and delete the key in the left or right subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's key to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (key > root->key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Driver program
int main() {
    struct Node* root = NULL;

    // Insert elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print in-order traversal of the BST
    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a key in the BST
    int searchKey = 40;
    struct Node* searchResult = search(root, searchKey);
    if (searchResult != NULL)
        printf("%d found in the BST.\n", searchKey);
    else
        printf("%d not found in the BST.\n", searchKey);

    // Delete a key from the BST
    int deleteKey = 30;
    root = deleteNode(root, deleteKey);
    printf("In-order traversal after deleting %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    // Free the memory allocated for the BST nodes
    // (This step is usually done at the end of the program)
    // Note: In a real-world scenario, you might want to implement a more robust memory management system.
    // Here, we're keeping it simple for educational purposes.
    free(root);

    return 0;
}
