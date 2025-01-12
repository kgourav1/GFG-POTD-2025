# Trapping Rain Water

def maxWater(self, arr):
    n = len(arr)
    if n == 0:
        return 0  # No water can be trapped in an empty array

    left, right = 0, n - 1  # Two pointers
    left_max, right_max = 0, 0  # Maximum heights from the left and right
    total_water = 0  # Total water trapped

    # Traverse the array using the two pointers
    while left <= right:
        if arr[left] <= arr[right]:
            # Process the left pointer
            if arr[left] >= left_max:
                left_max = arr[left]  # Update the left max height
            else:
                total_water += left_max - arr[left]  # Water trapped above the current block
            left += 1  # Move the left pointer to the right
        else:
            # Process the right pointer
            if arr[right] >= right_max:
                right_max = arr[right]  # Update the right max height
            else:
                total_water += right_max - arr[right]  # Water trapped above the current block
            right -= 1  # Move the right pointer to the left

    return total_water  # Return the total water trapped
