class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

function reverseList(head) {
    let prev = null; // Initialize previous pointer
    let curr = head; // Start with the head of the list

    while (curr !== null) {
        let nextNode = curr.next; // Store the next node
        curr.next = prev;         // Reverse the current node's pointer
        prev = curr;              // Move the previous pointer forward
        curr = nextNode;          // Move the current pointer forward
    }

    return prev; // New head of the reversed list
}
