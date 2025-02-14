class Solution {
    constructor() {
        this.first = null;
        this.second = null;
        this.prev = null;
    }

    inorder(root) {
        if (!root) return;

        this.inorder(root.left); // Traverse left subtree

        // Identify swapped nodes
        if (this.prev && root.val < this.prev.val) {
            if (!this.first) this.first = this.prev; // First incorrect node
            this.second = root;  // Second incorrect node (updated if needed)
        }

        this.prev = root; // Move to the next node

        this.inorder(root.right); // Traverse right subtree
    }

    correctBST(root) {
        this.inorder(root); // Identify misplaced nodes
        if (this.first && this.second) {
            [this.first.val, this.second.val] = [this.second.val, this.first.val]; // Swap values to restore BST
        }
    }
}
