// Helper function to count paths with sum k
int countPaths(Node* root, int k, int currentSum, unordered_map<int, int>& prefixSum) {
    if (!root) return 0;

    // Update the current sum
    currentSum += root->data;

    // Count valid paths ending at this node
    int count = prefixSum[currentSum - k];

    // Update prefix sum map
    prefixSum[currentSum]++;

    // Recur for left and right children
    count += countPaths(root->left, k, currentSum, prefixSum);
    count += countPaths(root->right, k, currentSum, prefixSum);

    // Backtrack - remove the current sum from map
    prefixSum[currentSum]--;

    return count;
}

// Main function to count paths summing to k
int pathSum(Node* root, int k) {
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1; // Handle the case where the path itself equals k
    return countPaths(root, k, 0, prefixSum);
}
