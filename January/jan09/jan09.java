// Function to find the 1-based indexes of a subarray whose sum equals the target
static ArrayList<Integer> subarraySum(int[] arr, int target) {
    int i = 0; // Initialize the starting pointer of the sliding window
    int sum = 0; // Initialize the sum of the current window

    // Iterate through the array with the ending pointer of the sliding window
    for (int j = 0; j < arr.length; j++) {
        sum += arr[j]; // Add the current element to the sum

        // While the current sum is greater than the target and the window is valid
        while (sum > target && i <= j) {
            sum -= arr[i]; // Remove the element at the start of the window
            i++; // Shrink the window from the left
        }

        // If the sum of the current window equals the target
        if (sum == target) {
            // Return the 1-based indexes of the start and end of the subarray
            ArrayList<Integer> result = new ArrayList<>();
            result.add(i + 1);
            result.add(j + 1);
            return result;
        }
    }

    // If no subarray with the given sum is found, return -1
    ArrayList<Integer> result = new ArrayList<>();
    result.add(-1);
    return result;
}
