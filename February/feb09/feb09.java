class Solution {
    // Helper function to compute the maximum path sum
    private int getMaxPathSum(Node root, int[] maxSum) {
        if (root == null) return 0; // Base case: If node is null, return 0
        
        // Recursively get the maximum sum from left and right subtrees
        int leftMax = Math.max(0, getMaxPathSum(root.left, maxSum));  // Ignore negative sums
        int rightMax = Math.max(0, getMaxPathSum(root.right, maxSum));

        // Update the maximum path sum considering the current node as the root of the path
        maxSum[0] = Math.max(maxSum[0], root.data + leftMax + rightMax);

        // Return the maximum sum of the path including the current node and either left or right subtree
        return root.data + Math.max(leftMax, rightMax);
    }

    // Main function to find the maximum path sum in the binary tree
    public int findMaxSum(Node root) {
        int[] maxSum = {Integer.MIN_VALUE}; // Use an array to store max sum (to avoid pass-by-value issue)
        getMaxPathSum(root, maxSum);
        return maxSum[0];
    }
}
