public class Solution {
    // Function to find the length of the longest subarray with sum K
    public int LongestSubarray(int[] arr, int k) {
        Dictionary<int, int> prefixSumIndex = new Dictionary<int, int>(); // To store the first occurrence of each prefix sum
        int sum = 0;                                                     // Current prefix sum
        int maxLength = 0;                                               // Length of the longest subarray with sum = k

        // Traverse the array
        for (int i = 0; i < arr.Length; i++) {
            sum += arr[i]; // Update the prefix sum

            // Case 1: If the prefix sum is equal to k, update maxLength
            if (sum == k) {
                maxLength = Math.Max(maxLength, i + 1);
            }

            // Case 2: If (sum - k) exists in the dictionary, we found a subarray with sum = k
            if (prefixSumIndex.ContainsKey(sum - k)) {
                maxLength = Math.Max(maxLength, i - prefixSumIndex[sum - k]);
            }

            // Case 3: Store the first occurrence of the current prefix sum
            if (!prefixSumIndex.ContainsKey(sum)) {
                prefixSumIndex[sum] = i;
            }
        }

        return maxLength; // Return the length of the longest subarray
    }
}
