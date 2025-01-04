def countPairs(arr, target):
    """
    Function to count pairs in the array whose sum is less than the target.

    :param arr: List[int] - List of integers
    :param target: int - Target sum
    :return: int - Count of valid pairs
    """
    # Step 1: Sort the array in ascending order
    # Sorting helps in applying the two-pointer technique efficiently
    arr.sort()

    # Step 2: Initialize pointers and the count variable
    left = 0               # Points to the beginning of the array
    right = len(arr) - 1   # Points to the end of the array
    count = 0              # Tracks the number of valid pairs

    # Step 3: Iterate until the left pointer is less than the right pointer
    while left < right:
        # Calculate the sum of the elements at the two pointers
        current_sum = arr[left] + arr[right]

        # Step 4: Check if the sum is less than the target
        if current_sum < target:
            # All pairs between the current `left` and `right` will have sums < target
            # Valid pairs include (arr[left], arr[right]), (arr[left], arr[right-1]), ..., (arr[left], arr[left+1])
            count += (right - left)

            # Move the left pointer to the right to check the next potential pair
            left += 1
        else:
            # If the sum is greater than or equal to the target, move the right pointer to the left
            # This decreases the sum and may result in valid pairs
            right -= 1

    # Step 5: Return the total count of valid pairs
    return count
