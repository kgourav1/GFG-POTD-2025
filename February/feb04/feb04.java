class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class BinaryTree {
    // Helper function to calculate height and update diameter
    private static int solve(Node node, int[] diameter) {
        if (node == null) return 0; // Base case: If node is NULL, height is 0

        // Recursively find the height of left and right subtrees
        int leftHeight = solve(node.left, diameter);
        int rightHeight = solve(node.right, diameter);

        // Update the maximum diameter found so far
        diameter[0] = Math.max(diameter[0], leftHeight + rightHeight);

        // Return the height of the current node
        return 1 + Math.max(leftHeight, rightHeight);
    }

    public static int diameter(Node root) {
        int[] diameter = new int[1]; // Variable to store the maximum diameter
        solve(root, diameter); // Call helper function
        return diameter[0]; // Return the final diameter
    }
}
