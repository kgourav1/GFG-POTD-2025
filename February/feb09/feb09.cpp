// Helper function to compute the maximum path sum
    int getMaxPathSum(Node* root, int &maxSum) {
        if (!root) return 0; // Base case: If node is null, return 0
        
        // Recursively get the maximum sum from left and right subtrees
        int leftMax = max(0, getMaxPathSum(root->left, maxSum));  // Ignore negative sums
        int rightMax = max(0, getMaxPathSum(root->right, maxSum));

        // Update the maximum path sum considering the current node as the root of the path
        maxSum = max(maxSum, root->data + leftMax + rightMax);

        // Return the maximum sum of the path including the current node and either left or right subtree
        return root->data + max(leftMax, rightMax);
    }

    // Main function to find the maximum path sum in the binary tree
    int findMaxSum(Node *root) {
        int maxSum = INT_MIN; // Initialize max sum as the smallest possible integer
        getMaxPathSum(root, maxSum);
        return maxSum;
    }
