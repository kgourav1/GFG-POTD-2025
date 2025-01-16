// Largest subarray of 0's and 1's

function maxLen(arr) {
    const prefixSumIndex = new Map(); // Map to store the first occurrence of each prefix sum
    let sum = 0; // Current prefix sum
    let maxLen = 0; // Length of the longest subarray with equal 0s and 1s
    const k = 0; // Target sum (0 for equal number of 0s and 1s)

    // Traverse the array
    for (let i = 0; i < arr.length; i++) {
        // Update the prefix sum; treat 0 as -1 to balance 0s and 1s
        sum += arr[i] === 0 ? -1 : 1;

        // Case 1: If the prefix sum is equal to the target sum (k)
        if (sum === k) {
            maxLen = Math.max(maxLen, i + 1); // Update maxLen for subarray starting at index 0
        }

        // Case 2: If (sum - k) exists in the map
        if (prefixSumIndex.has(sum - k)) {
            maxLen = Math.max(maxLen, i - prefixSumIndex.get(sum - k)); // Update maxLen
        }

        // Case 3: Store the first occurrence of the current prefix sum
        if (!prefixSumIndex.has(sum)) {
            prefixSumIndex.set(sum, i); // Store index only if it's the first occurrence
        }
    }

    return maxLen; // Return the length of the longest subarray
}
