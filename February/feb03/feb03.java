class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class BinaryTree {
    // Function to find the height of a binary tree
    public static int height(Node node) {
        // Base case: If the node is null, return -1 (height of an empty tree)
        if (node == null) return -1;

        // Recursively calculate the height of left and right subtrees
        int leftHeight = height(node.left);
        int rightHeight = height(node.right);

        // Return the maximum height of the two subtrees + 1 (for the current node)
        return Math.max(leftHeight, rightHeight) + 1;
    }
}
