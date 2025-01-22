
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Helper function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

// Function to remove leading zeros from a linked list
Node* removeLeadingZeros(Node* head) {
    // Traverse the list until we find a non-zero node
    while (head && head->data == 0) {
        head = head->next; // Skip the leading zero nodes
    }
    return head; // Return the list starting from the first non-zero node
}

Node* addTwoLists(Node* num1, Node* num2) {
    // Step 1: Reverse both input lists
    num1 = reverseList(num1);
    num2 = reverseList(num2);

    Node* dummy = new Node(0);  // Dummy node to build the result list
    Node* current = dummy;
    int carry = 0;

    // Step 2: Add the reversed lists
    while (num1 || num2 || carry) {
        int sum = carry;

        if (num1) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        // Append the digit to the result list
        current->next = new Node(digit);
        current = current->next;
    }

    // Step 3: Reverse the result list to get the final answer
    Node* result = reverseList(dummy->next);

    // Step 4: Remove leading zeros if present in the result
    return removeLeadingZeros(result);
}
