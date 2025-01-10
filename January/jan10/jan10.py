# Count distinct elements in every window

def countDistinct(self, arr, k):
    result = []  # Store the result
    freq_map = {}  # Track frequency of elements

    # Initialize the first window
    for i in range(k):
        freq_map[arr[i]] = freq_map.get(arr[i], 0) + 1
    result.append(len(freq_map))  # Add the count of distinct elements in the first window

    # Slide the window across the array
    for i in range(k, len(arr)):
        # Remove the element sliding out of the window
        freq_map[arr[i - k]] -= 1
        if freq_map[arr[i - k]] == 0:
            del freq_map[arr[i - k]]

        # Add the new element to the window
        freq_map[arr[i]] = freq_map.get(arr[i], 0) + 1

        # Add the count of distinct elements in the current window
        result.append(len(freq_map))

    return result  # Return the result
