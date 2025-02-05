
// Helper function to construct the binary tree
Node* constructTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &inorderMap, int &preIndex, int inStart, int inEnd) {
    // Base case
    if (inStart > inEnd) return nullptr;

    // Pick the current node from preorder traversal
    int rootValue = preorder[preIndex++];
    Node* root = new Node(rootValue);

    // Find the root index in inorder traversal
    int rootIndex = inorderMap[rootValue];

    // Recursively build left and right subtrees
    root->left = constructTree(preorder, inorder, inorderMap, preIndex, inStart, rootIndex - 1);
    root->right = constructTree(preorder, inorder, inorderMap, preIndex, rootIndex + 1, inEnd);

    return root;
}

// Function to build the tree from given inorder and preorder traversals
Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
    unordered_map<int, int> inorderMap;
    int n = inorder.size();
    
    // Store indices of inorder elements for O(1) access
    for (int i = 0; i < n; i++) {
        inorderMap[inorder[i]] = i;
    }

    int preIndex = 0;
    return constructTree(preorder, inorder, inorderMap, preIndex, 0, n - 1);
}
