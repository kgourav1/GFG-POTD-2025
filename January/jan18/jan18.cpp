// Reverse a linked list

Node* reverseList(Node* head) {
    Node* prev = nullptr; // Initialize previous pointer
    Node* curr = head;    // Start with the head of the list

    while (curr != nullptr) {
        Node* nextNode = curr->next; // Store the next node
        curr->next = prev;           // Reverse the current node's pointer
        prev = curr;                 // Move the previous pointer forward
        curr = nextNode;             // Move the current pointer forward
    }

    return prev; // New head of the reversed list
}
