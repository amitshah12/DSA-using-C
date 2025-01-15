#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} BST;

struct node *insertBST(struct node *root, int data) {
  if (root == NULL) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }

  if (data < root->data) {
    root->left = insertBST(root->left, data);
  } else {
    root->right = insertBST(root->right, data);
  }

  return root;
}

void inorder(struct node *root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int main() {
  struct node *root;
  root = NULL;

  root = insertBST(root, 5);
  insertBST(root, 1);
  insertBST(root, 3);
  insertBST(root, 4);
  insertBST(root, 2);
  insertBST(root, 7);

  printf("Inorder traversal: ");
  inorder(root);

  return 0;
}
