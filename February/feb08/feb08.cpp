void boundaryTraversalUtil(Node* root, vector<int>& ans, bool isLeftBoundary, bool isRightBoundary) {
        if (!root) return;

        // Add root if it's a left boundary or a leaf node
        if (isLeftBoundary || (!root->left && !root->right)) 
            ans.push_back(root->data);
        
        // Recursive call for left and right subtrees
        boundaryTraversalUtil(root->left, ans, isLeftBoundary, isRightBoundary && !root->right);
        boundaryTraversalUtil(root->right, ans, isLeftBoundary && !root->left, isRightBoundary);
        
        // Add root if it's a right boundary (but after recursive calls)
        if (isRightBoundary && !(isLeftBoundary || (!root->left && !root->right))) 
            ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code hereif (!root) return {};
        vector<int> ans;
        ans.push_back(root->data);
        boundaryTraversalUtil(root->left, ans, true, false);  // Left boundary and leaves
        boundaryTraversalUtil(root->right, ans, false, true); // Right boundary
        return ans;
    }
