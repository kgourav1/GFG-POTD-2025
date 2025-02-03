// Function to find the height of a binary tree
int height(Node* node) {
    // Base case: If the node is NULL, return -1 (height of an empty tree)
    if (node == NULL) return -1;
    
    // Recursively find the height of left and right subtrees
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    // Return the maximum of left and right subtree heights + 1 (for the current node)
    return max(leftHeight, rightHeight) + 1;
}
