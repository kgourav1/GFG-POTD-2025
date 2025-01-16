// Largest subarray of 0's and 1's

public int maxLen(int[] arr) {
    HashMap<Integer, Integer> prefixSumIndex = new HashMap<>(); // Map to store the first occurrence of each prefix sum
    int sum = 0; // Current prefix sum
    int maxLen = 0; // Length of the longest subarray with equal 0s and 1s
    int k = 0; // Target sum (0 for equal number of 0s and 1s)

    // Traverse the array
    for (int i = 0; i < arr.length; i++) {
        // Update the prefix sum; treat 0 as -1 to balance 0s and 1s
        sum += (arr[i] == 0) ? -1 : 1;

        // Case 1: If the prefix sum is equal to the target sum (k)
        if (sum == k) {
            maxLen = Math.max(maxLen, i + 1); // Update maxLen for subarray starting at index 0
        }

        // Case 2: If (sum - k) exists in the map
        if (prefixSumIndex.containsKey(sum - k)) {
            maxLen = Math.max(maxLen, i - prefixSumIndex.get(sum - k)); // Update maxLen
        }

        // Case 3: Store the first occurrence of the current prefix sum
        if (!prefixSumIndex.containsKey(sum)) {
            prefixSumIndex.put(sum, i); // Store index only if it's the first occurrence
        }
    }

    return maxLen; // Return the length of the longest subarray
}
