 // Helper function to calculate height and update diameter
    int solve(Node* node, int &diameter) {
        if (!node) return 0; // Base case: If node is NULL, height is 0
        
        // Recursively find the height of left and right subtrees
        int leftHeight = solve(node->left, diameter);
        int rightHeight = solve(node->right, diameter);
        
        // Update the maximum diameter found so far
        diameter = max(diameter, leftHeight + rightHeight); 
        
        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }
    
    int diameter(Node* root) {
        int diameter = 0; // Variable to store the maximum diameter
        solve(root, diameter); // Call helper function
        return diameter; // Return the final diameter
    }
