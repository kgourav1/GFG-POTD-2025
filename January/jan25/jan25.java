class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class CycleDetection {
    public static Node findFirstNode(Node head) {
        Node slow = head; // Initialize the slow pointer
        Node fast = head; // Initialize the fast pointer

        // Step 1: Detect if there is a cycle using slow and fast pointers
        while (fast != null && fast.next != null) {
            slow = slow.next; // Move slow pointer by one step
            fast = fast.next.next; // Move fast pointer by two steps
            if (slow == fast) break; // Cycle detected
        }

        // Step 2: If no cycle is detected, return -1
        if (slow != fast) return new Node(-1);

        // Step 3: Find the first node of the cycle
        slow = head; // Reset slow pointer to the head
        while (slow != fast) {
            slow = slow.next; // Move both pointers one step at a time
            fast = fast.next;
        }

        return fast; // The first node of the cycle
    }
}
