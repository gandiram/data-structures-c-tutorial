#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Structure definition for a binary tree node
typedef struct Node {
    int data;         // Data to be stored in the node
    struct Node* left;  // Pointer to the left child
    struct Node* right; // Pointer to the right child
} Node;

// Function prototypes for binary tree operations
Node* createNode(int data);
void insert(Node** root, int data);
void inorderTraversal(Node* root);
void preorderTraversal(Node* root);
void postorderTraversal(Node* root);
int search(Node* root, int key);
void deleteNode(Node** root, int key);
void freeTree(Node* root);

#endif // BINARY_TREE_H
