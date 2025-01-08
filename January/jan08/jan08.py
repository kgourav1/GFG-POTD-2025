
# Function to count the number of possible triangles
def countTriangles(self, arr):
    # Step 1: Sort the array in ascending order
    arr.sort()

    count = 0  # Initialize the count of triangles
    n = len(arr)  # Get the size of the array

    # Step 2: Fix the largest side of the triangle
    for k in range(n - 1, 1, -1):
        i = 0           # Start pointer
        j = k - 1       # End pointer (just before the fixed side)

        # Step 3: Use the two-pointer technique to find valid pairs
        while i < j:
            # Check if the sum of arr[i] and arr[j] is greater than arr[k]
            if arr[i] + arr[j] > arr[k]:
                # If valid, all pairs between i and j are valid
                count += (j - i)

                # Move the end pointer left to check for other combinations
                j -= 1
            else:
                # If not valid, move the start pointer right to increase the sum
                i += 1

    # Step 4: Return the total count of triangles
    return count
