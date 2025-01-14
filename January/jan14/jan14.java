// Function to find the equilibrium point in the array

public int findEquilibrium(int[] arr) {
    int prefixSum = Arrays.stream(arr).sum(); // Calculate total sum of the array
    int sum = 0; // Variable to keep track of the left sum

    // Traverse the array
    for (int i = 0; i < arr.length; i++) {
        sum += arr[i]; // Update the left sum to include the current element

        // Check if left sum equals the right sum
        if (sum == prefixSum) {
            return i; // Return the equilibrium index
        }

        prefixSum -= arr[i]; // Update the prefix sum by removing the current element
    }

    return -1; // Return -1 if no equilibrium point is found
}
