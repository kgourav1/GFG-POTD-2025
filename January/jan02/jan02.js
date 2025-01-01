// User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */

countSubarrays(arr, k) {
    // Create a Map to store the frequency of prefix sums
    const prefixSumMap = new Map();

    // Variable to store the count of subarrays with sum k
    let count = 0;

    // Variable to keep track of the prefix sum
    let prefixSum = 0;

    // Initialize the map with prefixSum = 0 occurring once
    // This handles cases where a subarray starting from index 0 has sum equal to k
    prefixSumMap.set(0, 1);

    // Traverse through each element in the array
    for (let num of arr) {
        // Update the prefix sum by adding the current element
        prefixSum += num;

        // Check if there exists a prefix sum such that:
        // prefixSum - (prefixSum - k) = k
        // If prefixSum - k exists in the map, it means there is a subarray with sum k
        if (prefixSumMap.has(prefixSum - k)) {
            // Add the frequency of (prefixSum - k) to the count
            count += prefixSumMap.get(prefixSum - k);
        }

        // Increment the frequency of the current prefixSum in the map
        prefixSumMap.set(prefixSum, (prefixSumMap.get(prefixSum) || 0) + 1);
    }

    // Return the total count of subarrays with sum equal to k
    return count;
}
