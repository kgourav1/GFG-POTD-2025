Node* reverseKGroup(Node* head, int k) {
    if (!head) return nullptr; // If the list is empty, return null

    Node* prev = nullptr;     // Initialize previous pointer for reversal
    Node* curr = head;        // Start with the head of the list
    Node* nextNode = nullptr; // Pointer to store the next node
    int count = 0;            // Counter to track the number of nodes reversed

    // Reverse `k` nodes in the group
    while (curr != nullptr && count < k) {
        nextNode = curr->next; // Store the next node
        curr->next = prev;     // Reverse the current node's pointer
        prev = curr;           // Move the previous pointer forward
        curr = nextNode;       // Move the current pointer forward
        count++;               // Increment the counter
    }

    // Recursive call to process the remaining nodes
    if (nextNode) {
        head->next = reverseKGroup(nextNode, k); // Connect the end of the reversed group to the next reversed group
    }

    return prev; // Return the new head of the reversed group
}
