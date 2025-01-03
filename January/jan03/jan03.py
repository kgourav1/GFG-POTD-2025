def subarrayXor(self, arr, k):
    """
    Function to count the number of subarrays with XOR equal to k.

    Parameters:
    arr (list): List of integers representing the array.
    k (int): Target XOR value.

    Returns:
    int: The count of subarrays with XOR equal to k.
    """

    # Dictionary to store the frequency of XOR prefix sums
    xor_map = {}

    # Variable to count the number of subarrays with XOR equal to k
    count = 0

    # Variable to keep track of the prefix XOR value
    prefix_xor = 0

    # Initialize the dictionary with prefix_xor = 0 occurring once
    # This handles cases where the XOR of a subarray starting from index 0 equals k
    xor_map[0] = 1

    # Traverse through each element in the array
    for num in arr:
        # Update the prefix XOR value with the current element
        prefix_xor ^= num

        # Check if there exists a prefix XOR value such that:
        # prefix_xor ^ (prefix_xor ^ k) = k
        # If prefix_xor ^ k exists in the dictionary, it means there is a subarray with XOR equal to k
        if prefix_xor ^ k in xor_map:
            # Add the frequency of (prefix_xor ^ k) to the count
            count += xor_map[prefix_xor ^ k]

        # Increment the frequency of the current prefix XOR value in the dictionary
        xor_map[prefix_xor] = xor_map.get(prefix_xor, 0) + 1

    # Return the total count of subarrays with XOR equal to k
    return count
