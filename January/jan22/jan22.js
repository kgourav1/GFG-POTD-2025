class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

// Helper function to reverse a linked list
function reverseList(head) {
    let prev = null;
    let current = head;
    while (current !== null) {
        let nextNode = current.next;
        current.next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

// Function to remove leading zeros from a linked list
function removeLeadingZeros(head) {
    while (head && head.data === 0) {
        head = head.next; // Skip the leading zero nodes
    }
    return head;
}

// Function to add two linked lists
function addTwoLists(num1, num2) {
    // Step 1: Reverse both input lists
    num1 = reverseList(num1);
    num2 = reverseList(num2);

    let dummy = new Node(0); // Dummy node to build the result list
    let current = dummy;
    let carry = 0;

    // Step 2: Add the reversed lists
    while (num1 || num2 || carry) {
        let sum = carry;

        if (num1) {
            sum += num1.data;
            num1 = num1.next;
        }

        if (num2) {
            sum += num2.data;
            num2 = num2.next;
        }

        carry = Math.floor(sum / 10);
        let digit = sum % 10;

        // Append the digit to the result list
        current.next = new Node(digit);
        current = current.next;
    }

    // Step 3: Reverse the result list to get the final answer
    let result = reverseList(dummy.next);

    // Step 4: Remove leading zeros if present in the result
    return removeLeadingZeros(result);
}
