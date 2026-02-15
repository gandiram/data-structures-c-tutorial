# Test Cases for Linked Lists

## Singly Linked List Tests

void test_singly_linked_list() {
    struct Node* head = NULL;
    // Test insertion at the front
    insert_front(&head, 1);
    assert(head->data == 1);

    // Test insertion at the end
    insert_end(&head, 2);
    assert(head->next->data == 2);

    // Test deletion
    delete_node(&head, 1);
    assert(head->data == 2);

    // Test search
    assert(search(head, 2) != NULL);
    assert(search(head, 1) == NULL);
}

## Circular Linked List Tests

void test_circular_linked_list() {
    struct Node* head = NULL;
    insert_end(&head, 1);
    insert_end(&head, 2);
    make_circular(&head);
    // Test if it is circular
    assert(is_circular(head) == true);
}

## Doubly Linked List Tests

void test_doubly_linked_list() {
    struct DNode* head = NULL;
    insert_front_doubly(&head, 1);
    assert(head->data == 1);

    insert_end_doubly(&head, 2);
    assert(head->next->data == 2);

    delete_node_doubly(&head, 1);
    assert(head->data == 2);
}

int main() {
    test_singly_linked_list();
    test_circular_linked_list();
    test_doubly_linked_list();
    return 0;
}