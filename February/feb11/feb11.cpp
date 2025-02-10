bool isValidBST(Node* root, int minVal, int maxVal) {
    if (!root) return true;  // Base case: empty tree is valid

    // Check BST property violation
    if (root->data <= minVal || root->data >= maxVal) return false;

    // Recursively validate left and right subtrees with updated constraints
    return isValidBST(root->left, minVal, root->data) &&
           isValidBST(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isValidBST(root, INT_MIN, INT_MAX);
}
