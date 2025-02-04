using System;

class Node {
    public int data;
    public Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class BinaryTree {
    // Helper function to calculate height and update diameter
    private static int Solve(Node node, ref int diameter) {
        if (node == null) return 0; // Base case: If node is NULL, height is 0

        // Recursively find the height of left and right subtrees
        int leftHeight = Solve(node.left, ref diameter);
        int rightHeight = Solve(node.right, ref diameter);

        // Update the maximum diameter found so far
        diameter = Math.Max(diameter, leftHeight + rightHeight);

        // Return the height of the current node
        return 1 + Math.Max(leftHeight, rightHeight);
    }

    public static int Diameter(Node root) {
        int diameter = 0; // Variable to store the maximum diameter
        Solve(root, ref diameter); // Call helper function
        return diameter; // Return the final diameter
    }
}
