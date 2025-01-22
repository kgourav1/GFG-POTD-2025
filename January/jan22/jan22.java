class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedList {
    // Helper function to reverse a linked list
    private Node reverseList(Node head) {
        Node prev = null;
        Node current = head;
        while (current != null) {
            Node nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    // Function to remove leading zeros from a linked list
    private Node removeLeadingZeros(Node head) {
        while (head != null && head.data == 0) {
            head = head.next; // Skip the leading zero nodes
        }
        return head;
    }

    // Function to add two linked lists
    public Node addTwoLists(Node num1, Node num2) {
        // Step 1: Reverse both input lists
        num1 = reverseList(num1);
        num2 = reverseList(num2);

        Node dummy = new Node(0); // Dummy node to build the result list
        Node current = dummy;
        int carry = 0;

        // Step 2: Add the reversed lists
        while (num1 != null || num2 != null || carry != 0) {
            int sum = carry;

            if (num1 != null) {
                sum += num1.data;
                num1 = num1.next;
            }

            if (num2 != null) {
                sum += num2.data;
                num2 = num2.next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            // Append the digit to the result list
            current.next = new Node(digit);
            current = current.next;
        }

        // Step 3: Reverse the result list to get the final answer
        Node result = reverseList(dummy.next);

        // Step 4: Remove leading zeros if present in the result
        return removeLeadingZeros(result);
    }
}
