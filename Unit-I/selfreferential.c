// selfreferential.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct DoubleNode {
    int data;
    struct DoubleNode *next;
    struct DoubleNode *prev;
};

void displayLinkedList(struct Node *head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void inorder(struct TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    printf("Self-Referential Structures Examples\n\n");
    
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = NULL;
    displayLinkedList(head);
    free(head->next);
    free(head);
    
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = 1;
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    printf("Tree Inorder: ");
    inorder(root);
    printf("\n");
    free(root->left);
    free(root->right);
    free(root);
    
    struct DoubleNode *dhead = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
    dhead->data = 100;
    dhead->next = NULL;
    dhead->prev = NULL;
    printf("Doubly Linked List node: %d\n", dhead->data);
    free(dhead);
    
    return 0;
}
