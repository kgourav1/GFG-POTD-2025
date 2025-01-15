// Longest Subarray with Sum K

function longestSubarray(arr, k) {
    const prefixSumIndex = new Map(); // To store the first occurrence of each prefix sum
    let sum = 0;                     // Current prefix sum
    let maxLength = 0;               // Length of the longest subarray with sum = k

    // Traverse the array
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i]; // Update the prefix sum

        // Case 1: If the prefix sum is equal to k, update maxLength
        if (sum === k) {
            maxLength = Math.max(maxLength, i + 1);
        }

        // Case 2: If (sum - k) exists in the map, we found a subarray with sum = k
        if (prefixSumIndex.has(sum - k)) {
            maxLength = Math.max(maxLength, i - prefixSumIndex.get(sum - k));
        }

        // Case 3: Store the first occurrence of the current prefix sum
        if (!prefixSumIndex.has(sum)) {
            prefixSumIndex.set(sum, i);
        }
    }

    return maxLength; // Return the length of the longest subarray
}
