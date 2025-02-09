class Solution {
    // Helper function to compute the maximum path sum
    private int GetMaxPathSum(Node root, ref int maxSum) {
        if (root == null) return 0; // Base case: If node is null, return 0

        // Recursively get the maximum sum from left and right subtrees
        int leftMax = Math.Max(0, GetMaxPathSum(root.left, ref maxSum));  // Ignore negative sums
        int rightMax = Math.Max(0, GetMaxPathSum(root.right, ref maxSum));

        // Update the maximum path sum considering the current node as the root of the path
        maxSum = Math.Max(maxSum, root.data + leftMax + rightMax);

        // Return the maximum sum of the path including the current node and either left or right subtree
        return root.data + Math.Max(leftMax, rightMax);
    }

    // Main function to find the maximum path sum in the binary tree
    public int FindMaxSum(Node root) {
        int maxSum = int.MinValue; // Initialize max sum as the smallest possible integer
        GetMaxPathSum(root, ref maxSum);
        return maxSum;
    }
}
