class Solution:
    # Container With Most Water
    def maxWater(self, arr):
        area = 0  # Variable to store the maximum water area
        left, right = 0, len(arr) - 1  # Two pointers: left and right

        # Traverse the array with two pointers
        while left < right:
            h = min(arr[left], arr[right])  # Calculate the height of the container
            w = right - left                # Calculate the width of the container
            area = max(area, h * w)         # Update the maximum area if the current area is larger

            # Move the pointers based on the heights
            if arr[left] > arr[right]:
                right -= 1  # Move the right pointer left if the right height is smaller
            else:
                left += 1   # Move the left pointer right if the left height is smaller or equal

        return area  # Return the maximum water area found
