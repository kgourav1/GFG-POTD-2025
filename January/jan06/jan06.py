def sumClosest(self, arr, target):
    """
    Finds the pair of numbers in the array whose sum is closest to the target.

    :param arr: List[int] - The input array of integers
    :param target: int - The target sum
    :return: List[int] - A list containing the pair whose sum is closest to the target
    """
    # Step 1: Sort the array to use the two-pointer technique
    arr.sort()

    # Initialize variables to track the closest difference and result pair
    closest_diff = float('inf')  # Represents the smallest difference found
    result = []  # Stores the pair with the closest sum

    # Initialize two pointers
    left = 0  # Points to the start of the array
    right = len(arr) - 1  # Points to the end of the array

    # Step 2: Iterate using the two-pointer technique
    while left < right:
        # Calculate the sum of the elements at the two pointers
        current_sum = arr[left] + arr[right]

        # Calculate the absolute difference between the current sum and the target
        diff = abs(current_sum - target)

        # Step 3: Update the result if the current pair is closer
        if (diff < closest_diff or 
           (diff == closest_diff and (arr[right] - arr[left]) > (result[1] - result[0] if result else 0))):
            closest_diff = diff  # Update the closest difference
            result = [arr[left], arr[right]]  # Update the result pair

        # Step 4: Adjust pointers based on the current sum
        if current_sum < target:
            # If the sum is less than the target, move the left pointer to the right
            left += 1
        elif current_sum > target:
            # If the sum is greater than the target, move the right pointer to the left
            right -= 1
        else:
            # If the sum is exactly the target, it's the closest possible
            break

    # Step 5: Return the closest pair
    return result
