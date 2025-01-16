# Largest subarray of 0's and 1's

def maxLen(arr):
    prefix_sum_index = {}  # Dictionary to store the first occurrence of each prefix sum
    sum = 0  # Current prefix sum
    max_len = 0  # Length of the longest subarray with equal 0s and 1s
    k = 0  # Target sum (0 for equal number of 0s and 1s)

    # Traverse the array
    for i in range(len(arr)):
        # Update the prefix sum; treat 0 as -1 to balance 0s and 1s
        sum += -1 if arr[i] == 0 else 1

        # Case 1: If the prefix sum is equal to the target sum (k)
        if sum == k:
            max_len = max(max_len, i + 1)  # Update max_len for subarray starting at index 0

        # Case 2: If (sum - k) exists in the map
        if (sum - k) in prefix_sum_index:
            max_len = max(max_len, i - prefix_sum_index[sum - k])  # Update max_len

        # Case 3: Store the first occurrence of the current prefix sum
        if sum not in prefix_sum_index:
            prefix_sum_index[sum] = i  # Store index only if it's the first occurrence

    return max_len  # Return the length of the longest subarray
