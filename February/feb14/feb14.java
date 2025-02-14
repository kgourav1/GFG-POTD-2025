class Solution {
    private TreeNode first = null, second = null, prev = null;

    // Inorder traversal to find misplaced nodes
    private void inorder(TreeNode root) {
        if (root == null) return;

        inorder(root.left); // Traverse left subtree

        // Identify swapped nodes
        if (prev != null && root.val < prev.val) { 
            if (first == null) first = prev; // First incorrect node
            second = root;  // Second incorrect node (updated if needed)
        }
        
        prev = root; // Move to the next node

        inorder(root.right); // Traverse right subtree
    }

    public void correctBST(TreeNode root) {
        inorder(root); // Identify misplaced nodes
        if (first != null && second != null) {
            int temp = first.val;
            first.val = second.val;
            second.val = temp; // Swap values to restore BST
        }
    }
}
