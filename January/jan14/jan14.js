function findEquilibrium(arr) {
    let prefixSum = arr.reduce((acc, num) => acc + num, 0); // Calculate total sum of the array
    let leftSum = 0; // Variable to keep track of the left sum

    // Traverse the array
    for (let i = 0; i < arr.length; i++) {
        leftSum += arr[i]; // Update the left sum to include the current element

        // Check if left sum equals the right sum
        if (leftSum === prefixSum) {
            return i; // Return the equilibrium index
        }

        prefixSum -= arr[i]; // Update the prefix sum by removing the current element
    }

    return -1; // Return -1 if no equilibrium point is found
}
