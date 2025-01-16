// Largest subarray of 0's and 1's

int maxLen(vector<int> &arr) {
    unordered_map<int, int> prefixSumIndex; // Map to store the first occurrence of each prefix sum
    int sum = 0;                           // Current prefix sum
    int maxLen = 0;                        // Length of the longest subarray with equal 0s and 1s
    int k = 0;                             // Target sum (0 for equal number of 0s and 1s)

    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {
        // Update the prefix sum; treat 0 as -1 to calculate balance between 0s and 1s
        sum += (arr[i] == 0) ? -1 : 1;

        // Case 1: If the prefix sum is equal to the target sum (k)
        if (sum == k) {
            maxLen = max(maxLen, i + 1); // Update maxLen for subarray starting at index 0
        }

        // Case 2: If (sum - k) exists in the map, calculate the length of the subarray
        if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
            maxLen = max(maxLen, i - prefixSumIndex[sum - k]); // Update maxLen
        }

        // Case 3: Store the first occurrence of the current prefix sum
        if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
            prefixSumIndex[sum] = i; // Store index only if it's the first occurrence
        }
    }

    return maxLen; // Return the length of the longest subarray
}
