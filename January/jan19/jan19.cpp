// Rotate a Linked List

struct Node {
    int data;
    Node* next;
};

Node* rotate(Node* head, int k) {
    if (!head || k == 0) return head; // Handle empty list or no rotation

    // Step 1: Calculate length and connect the list into a circle
    Node* temp = head;
    int length = 1;

    while (temp->next) {
        temp = temp->next;
        length++;
    }
    temp->next = head; // Make the list circular

    // Step 2: Optimize k
    k = k % length; // If k >= length, take modulo
    if (k == 0) {   // If no rotation is needed, break the circle and return head
        temp->next = nullptr;
        return head;
    }

    // Step 3: Find the new tail
    int stepsToNewTail = k; // Traverse k steps to find the new tail
    Node* newTail = head;

    for (int i = 1; i < stepsToNewTail; i++) { // Move to the k-th node
        newTail = newTail->next;
    }

    Node* newHead = newTail->next; // New head is the next of new tail
    newTail->next = nullptr;       // Break the circle

    return newHead; // Return the new head of the rotated list
}
