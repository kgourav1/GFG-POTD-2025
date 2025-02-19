class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

function rotate(head, k) {
    if (!head || k === 0) return head; // Handle empty list or no rotation

    // Step 1: Calculate length and connect the list into a circle
    let temp = head;
    let length = 1;

    while (temp.next) {
        temp = temp.next;
        length++;
    }
    temp.next = head; // Make the list circular

    // Step 2: Optimize k
    k = k % length; // If k >= length, take modulo
    if (k === 0) {  // If no rotation is needed, break the circle and return head
        temp.next = null;
        return head;
    }

    // Step 3: Find the new tail
    let stepsToNewTail = k; // Traverse (k) steps to find the new tail
    let newTail = head;

    for (let i = 1; i < stepsToNewTail; i++) {
        newTail = newTail.next;
    }

    const newHead = newTail.next; // New head is the next of new tail
    newTail.next = null;          // Break the circle

    return newHead; // Return the new head of the rotated list
}
