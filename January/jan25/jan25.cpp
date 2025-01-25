// Function to detect the first node of the loop
Node* detectCycleStart(Node* head) {
    if (!head || !head->next) return nullptr; // No loop if the list is empty or has one node

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect the loop using Floyd’s Cycle Detection Algorithm
    while (fast && fast->next) {
        slow = slow->next;         // Move slow pointer by 1 step
        fast = fast->next->next;   // Move fast pointer by 2 steps

        if (slow == fast) { // Loop detected
            // Step 2: Find the start of the loop
            Node* entry = head; // Start one pointer from the head
            while (entry != slow) {
                entry = entry->next; // Move both pointers one step
                slow = slow->next;
            }
            return entry; // The first node in the loop
        }
    }

    return nullptr; // No loop
}
