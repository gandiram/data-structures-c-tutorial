/*
 * bst.c
 * Implementation of Binary Search Tree Operations in C
 *
 * This file contains the implementation of a Binary Search Tree (BST) with
 * operations for insertion, deletion, and search along with examples of each.
 * Each function is commented for clarity.
 *
 */

#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return newNode(data);
    }
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search a given key in BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }
    // Key is greater than root's key
    if (key > root->data) {
        return search(root->right, key);
    }
    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to find the minimum node in a given BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    // Base Case
    if (root == NULL) {
        return root;
    }
    // Recur down the tree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
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

        // Node with two children, get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the BST in order
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Example usage
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf(\"\n\");

    printf("\nDelete 20\");
    root = deleteNode(root, 20);
    printf("Inorder traversal: ");
    inorder(root);
    printf(\"\n\");

    printf("\nDelete 30\");
    root = deleteNode(root, 30);
    printf("Inorder traversal: ");
    inorder(root);
    printf(\"\n\");

    printf("\nDelete 50\");
    root = deleteNode(root, 50);
    printf("Inorder traversal: ");
    inorder(root);
    printf(\"\n\");

    return 0;
}