class Solution:
    # Function to find the length of the longest subarray with sum K
    def longestSubarray(self, arr, k):
        prefix_sum_index = {}  # To store the first occurrence of each prefix sum
        sum = 0                # Current prefix sum
        max_length = 0         # Length of the longest subarray with sum = k

        # Traverse the array
        for i in range(len(arr)):
            sum += arr[i]  # Update the prefix sum

            # Case 1: If the prefix sum is equal to k, update max_length
            if sum == k:
                max_length = max(max_length, i + 1)

            # Case 2: If (sum - k) exists in the map, we found a subarray with sum = k
            if (sum - k) in prefix_sum_index:
                max_length = max(max_length, i - prefix_sum_index[sum - k])

            # Case 3: Store the first occurrence of the current prefix sum
            if sum not in prefix_sum_index:
                prefix_sum_index[sum] = i

        return max_length  # Return the length of the longest subarray
