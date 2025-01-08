/**
 * Function to find the 1-based indexes of a subarray whose sum equals the target.
 * @param {number[]} arr - The input array.
 * @param {number} target - The target sum to find.
 * @returns {number[]} - An array containing the 1-based start and end indexes of the subarray, or [-1] if no such subarray exists.
 */
subarraySum(arr, target) {
    let i = 0; // Initialize the starting pointer of the sliding window
    let sum = 0; // Initialize the sum of the current window

    // Iterate through the array with the ending pointer of the sliding window
    for (let j = 0; j < arr.length; j++) {
        sum += arr[j]; // Add the current element to the sum

        // While the current sum is greater than the target and the window is valid
        while (sum > target && i <= j) {
            sum -= arr[i]; // Remove the element at the start of the window
            i++; // Shrink the window from the left
        }

        // If the sum of the current window equals the target
        if (sum === target) {
            // Return the 1-based indexes of the start and end of the subarray
            return [i + 1, j + 1];
        }
    }

    // If no subarray with the given sum is found, return -1
    return [-1];
}
