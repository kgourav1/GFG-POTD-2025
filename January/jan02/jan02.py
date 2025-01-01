def countSubarrays(self, arr, k):
    """
    Function to count the number of subarrays with a sum equal to k.

    Parameters:
    arr (List[int]): Input array of integers
    k (int): Target sum

    Returns:
    int: Total number of subarrays with sum equal to k
    """
    # Dictionary to store the frequency of prefix sums
    prefix_sum_map = {}

    # Variable to store the count of subarrays with sum k
    count = 0

    # Variable to keep track of the prefix sum
    prefix_sum = 0

    # Initialize the map with prefix_sum = 0 occurring once
    # This handles cases where a subarray starting from index 0 has sum equal to k
    prefix_sum_map[0] = 1

    # Traverse through each element in the array
    for num in arr:
        # Update the prefix sum by adding the current element
        prefix_sum += num

        # Check if there exists a prefix sum such that:
        # prefix_sum - (prefix_sum - k) = k
        # If prefix_sum - k exists in the map, it means there is a subarray with sum k
        if (prefix_sum - k) in prefix_sum_map:
            # Add the frequency of (prefix_sum - k) to the count
            count += prefix_sum_map[prefix_sum - k]

        # Increment the frequency of the current prefix_sum in the map
        prefix_sum_map[prefix_sum] = prefix_sum_map.get(prefix_sum, 0) + 1

    # Return the total count of subarrays with sum equal to k
    return count
