
# Function to find the equilibrium point in the array
def findEquilibrium(self, arr):
    prefix_sum = sum(arr)  # Calculate total sum of the array
    left_sum = 0  # Variable to keep track of the left sum

    # Traverse the array
    for i in range(len(arr)):
        left_sum += arr[i]  # Update the left sum to include the current element

        # Check if left sum equals the right sum
        if left_sum == prefix_sum:
            return i  # Return the equilibrium index

        prefix_sum -= arr[i]  # Update the prefix sum by removing the current element

    return -1  # Return -1 if no equilibrium point is found
