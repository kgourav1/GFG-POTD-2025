int kthSmallest(Node* root, int &k) {
    if (!root) return -1; // Base case: empty tree
    
    // Inorder traversal (left-root-right)
    int left = kthSmallest(root->left, k);
    if (k == 0) return left; // If kth smallest is found in left subtree, return

    k--; // Decrement k since we are visiting a node
    if (k == 0) return root->data; // If k reaches 0, we found the answer

    return kthSmallest(root->right, k); // Continue in right subtree
}
