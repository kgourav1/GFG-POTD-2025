def countTriplets(arr, target):
    """
    Function to count the number of triplets in the array whose sum equals the target value.

    Parameters:
    arr (list[int]): The input array of integers.
    target (int): The target sum for the triplets.

    Returns:
    int: The count of triplets whose sum equals the target.
    """
    n = len(arr)  # Get the size of the array
    count = 0     # Initialize the count of triplets to 0

    # Iterate over each element of the array as the first element of the triplet
    for i in range(n - 2):
        left = i + 1     # Left pointer starts right after the current element
        right = n - 1    # Right pointer starts at the end of the array

        # Perform a two-pointer approach to find triplets
        while left < right:
            triplet_sum = arr[i] + arr[left] + arr[right]  # Calculate the sum of the current triplet

            # Check if the triplet sum equals the target
            if triplet_sum == target:
                # Case 1: All elements between `left` and `right` are the same
                if arr[left] == arr[right]:
                    # Calculate the number of combinations using nC2 formula
                    length = right - left + 1
                    count += (length * (length - 1)) // 2  # Add the combinations to the count
                    break  # Exit the loop as all triplets for this range are counted

                # Case 2: Count duplicates of the left element
                left_count = 1  # At least one instance of the left element exists
                while left + 1 < right and arr[left] == arr[left + 1]:
                    left += 1  # Move the left pointer to count duplicates
                    left_count += 1

                # Count duplicates of the right element
                right_count = 1  # At least one instance of the right element exists
                while right - 1 > left and arr[right] == arr[right - 1]:
                    right -= 1  # Move the right pointer to count duplicates
                    right_count += 1

                # Add the product of left and right duplicates to the count
                count += left_count * right_count

                # Move both pointers to find the next potential triplet
                left += 1
                right -= 1

            elif triplet_sum > target:
                # If the sum is greater than the target, move the right pointer to reduce the sum
                right -= 1
            else:
                # If the sum is less than the target, move the left pointer to increase the sum
                left += 1

    # Return the total count of triplets with sum equal to the target
    return count
