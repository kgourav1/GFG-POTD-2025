public class Solution {
    // Function to find the length of the longest subarray with sum K
    public int longestSubarray(int[] arr, int k) {
        Map<Integer, Integer> prefixSumIndex = new HashMap<>(); // To store the first occurrence of each prefix sum
        int sum = 0;                                           // Current prefix sum
        int maxLength = 0;                                     // Length of the longest subarray with sum = k

        // Traverse the array
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i]; // Update the prefix sum

            // Case 1: If the prefix sum is equal to k, update maxLength
            if (sum == k) {
                maxLength = Math.max(maxLength, i + 1);
            }

            // Case 2: If (sum - k) exists in the map, we found a subarray with sum = k
            if (prefixSumIndex.containsKey(sum - k)) {
                maxLength = Math.max(maxLength, i - prefixSumIndex.get(sum - k));
            }

            // Case 3: Store the first occurrence of the current prefix sum
            prefixSumIndex.putIfAbsent(sum, i);
        }

        return maxLength; // Return the length of the longest subarray
    }
}
