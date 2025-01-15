//Longest Subarray with Sum K

int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumIndex; // To store the first occurrence of each prefix sum
    int sum = 0;                            // Current prefix sum
    int maxLength = 0;                      // Length of the longest subarray with sum = k

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // Update the prefix sum

        // Case 1: If the prefix sum is equal to k, update maxLength
        if (sum == k) {
            maxLength = max(maxLength, i + 1);
        }

        // Case 2: If (sum - k) exists in the map, we found a subarray with sum = k
        if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
            maxLength = max(maxLength, i - prefixSumIndex[sum - k]);
        }

        // Case 3: Store the first occurrence of the current prefix sum
        if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
            prefixSumIndex[sum] = i;
        }
    }

    return maxLength;
}
