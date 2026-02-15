# Linked List Examples

Welcome to the comprehensive guide on linked lists. This document covers the following topics:
- Node Creation
- Insertion
- Deletion
- Search
- Traversal
- Doubly Linked Lists
- Circular Linked Lists
- Advanced Operations

## 1. Node Creation
A linked list is made up of nodes, where each node contains data and a pointer/reference to the next node in the sequence.

```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

## 2. Insertion
### 2.1 Insert at the Beginning
```c
void insertAtBeginning(Node** head_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
```

### 2.2 Insert at the End
```c
void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}
```

## 3. Deletion
### 3.1 Delete a Node
```c
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
```

## 4. Search
### Search for an Element
```c
bool search(Node* head, int key) {
    Node* current = head;  
    while (current != NULL) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}
```

## 5. Traversal
### Traverse the Linked List
```c
void traverse(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
```

## 6. Doubly Linked Lists
An extension of linked lists where each node has a reference to the next and the previous node.

```c
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;
```

## 7. Circular Linked Lists
A linked list where the last node points back to the first node instead of pointing to NULL.

```c
void insertInCircularList(Node** head_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = new_node;
        return;
    }

    while (last->next != *head_ref) {
        last = last->next;
    }
    last->next = new_node;
}
```

## 8. Advanced Operations
  - Reversing a linked list
  - Finding the middle of the list
  - Detecting cycles

### Reverse the Linked List
```c
void reverse(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
```

### Detect Cycle
```c
bool hasCycle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
```

For further operations and explanations, feel free to check the literature on linked lists. Happy Coding!