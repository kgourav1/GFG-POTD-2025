class Solution {
    // Helper function to compute the maximum path sum
    getMaxPathSum(root, maxSum) {
        if (!root) return 0; // Base case: If node is null, return 0
        
        // Recursively get the maximum sum from left and right subtrees
        let leftMax = Math.max(0, this.getMaxPathSum(root.left, maxSum));  // Ignore negative sums
        let rightMax = Math.max(0, this.getMaxPathSum(root.right, maxSum));

        // Update the maximum path sum considering the current node as the root of the path
        maxSum.value = Math.max(maxSum.value, root.data + leftMax + rightMax);

        // Return the maximum sum of the path including the current node and either left or right subtree
        return root.data + Math.max(leftMax, rightMax);
    }

    // Main function to find the maximum path sum in the binary tree
    findMaxSum(root) {
        let maxSum = { value: Number.NEGATIVE_INFINITY }; // Use an object to store max sum (for pass-by-reference behavior)
        this.getMaxPathSum(root, maxSum);
        return maxSum.value;
    }
}
