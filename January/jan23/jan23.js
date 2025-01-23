class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.random = null;
    }
}

function cloneLinkedList(head) {
    if (!head) {
        return null;
    }

    // Step 1: Create new nodes and insert them next to the original nodes
    let curr = head;
    while (curr) {
        const newNode = new Node(curr.data); // Create a new node with the same data
        newNode.next = curr.next; // Link new node to the next of current node
        curr.next = newNode; // Insert the new node next to the current node
        curr = newNode.next; // Move to the next original node
    }

    // Step 2: Set the random pointers of the new nodes
    curr = head;
    while (curr) {
        if (curr.random) {
            curr.next.random = curr.random.next; // Point the random of new node to the clone of the random node
        }
        curr = curr.next.next; // Move to the next original node
    }

    // Step 3: Separate the new nodes from the original nodes
    curr = head;
    const clonedHead = head.next; // Save the head of the cloned list
    let clone = clonedHead;
    while (clone.next) {
        curr.next = curr.next.next; // Restore the next pointer of the original list
        clone.next = clone.next.next; // Restore the next pointer of the cloned list
        curr = curr.next; // Move to the next original node
        clone = clone.next; // Move to the next cloned node
    }
    curr.next = null; // Terminate the original list
    clone.next = null; // Terminate the cloned list

    return clonedHead; // Return the head of the cloned list
}
