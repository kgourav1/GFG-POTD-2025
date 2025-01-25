// Function to check if the linked list has a loop
bool detectLoop(Node* head) {
    // Initialize two pointers
    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow pointer by one step
        fast = fast->next->next;     // Move fast pointer by two steps

        // If slow and fast pointers meet, there is a loop
        if (slow == fast) {
            return true;
        }
    }

    // If fast pointer reaches the end, there is no loop
    return false;
}
