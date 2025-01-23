class Node {
    int data;
    Node next, random;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.random = null;
    }
}

public class CloneLinkedList {
    public Node cloneLinkedList(Node head) {
        if (head == null) {
            return null;
        }

        // Step 1: Create new nodes and insert them next to the original nodes
        Node curr = head;
        while (curr != null) {
            Node newNode = new Node(curr.data); // Create a new node with the same data
            newNode.next = curr.next; // Link new node to the next of current node
            curr.next = newNode; // Insert the new node next to the current node
            curr = newNode.next; // Move to the next original node
        }

        // Step 2: Set the random pointers of the new nodes
        curr = head;
        while (curr != null) {
            if (curr.random != null) {
                curr.next.random = curr.random.next; // Point the random of new node to the clone of the random node
            }
            curr = curr.next.next; // Move to the next original node
        }

        // Step 3: Separate the new nodes from the original nodes
        curr = head;
        Node clonedHead = head.next; // Save the head of the cloned list
        Node clone = clonedHead;
        while (clone.next != null) {
            curr.next = curr.next.next; // Restore the next pointer of the original list
            clone.next = clone.next.next; // Restore the next pointer of the cloned list
            curr = curr.next; // Move to the next original node
            clone = clone.next; // Move to the next cloned node
        }
        curr.next = null; // Terminate the original list
        clone.next = null; // Terminate the cloned list

        return clonedHead; // Return the head of the cloned list
    }
}
