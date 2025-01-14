// Function to find the equilibrium point in the array

int findEquilibrium(vector<int> &arr) {
    // Calculate the total sum of the array
    int prefixSum = accumulate(arr.begin(), arr.end(), 0);

    int sum = 0; // Variable to keep track of the sum of elements from the left

    // Traverse the array to find the equilibrium point
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // Update the sum to include the current element

        // Check if the left sum equals the right sum
        if (sum == prefixSum) {
            return i; // Return the current index as the equilibrium point
        }

        prefixSum -= arr[i]; // Reduce the total sum by the current element
    }

    return -1; // Return -1 if no equilibrium point is found
}
