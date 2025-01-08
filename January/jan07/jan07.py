def countPairs(self, arr, target):
    left = 0
    right = len(arr) - 1  # Initialize two pointers
    count = 0  # Initialize the count of pairs

    while left < right:
        sum_val = arr[left] + arr[right]  # Calculate the sum of the elements at the pointers

        if sum_val == target:
            # Case 1: When all elements between left and right are the same
            # Example: [1, 1, 1, 1], count pairs using combination formula nC2 = (n * (n - 1)) / 2
            if arr[left] == arr[right]:
                length = right - left + 1  # Total number of elements
                count += (length * (length - 1)) // 2  # Add all possible pairs
                break  # No need to continue further as all elements are processed

            # Case 2: Count duplicates on the left
            leftCount = 1  # Initialize the count for duplicates on the left
            while left < right and arr[left] == arr[left + 1]:
                leftCount += 1  # Increment count for duplicates
                left += 1  # Move the left pointer

            # Case 3: Count duplicates on the right
            rightCount = 1  # Initialize the count for duplicates on the right
            while right > left and arr[right] == arr[right - 1]:
                rightCount += 1  # Increment count for duplicates
                right -= 1  # Move the right pointer

            # Add the product of leftCount and rightCount to the total count
            count += leftCount * rightCount

            # Move both pointers inward to check for the next pair
            left += 1
            right -= 1
        elif sum_val > target:
            # If the sum is greater than the target, move the right pointer to reduce the sum
            right -= 1
        else:
            # If the sum is less than the target, move the left pointer to increase the sum
            left += 1

    return count  # Return the total count of pairs
