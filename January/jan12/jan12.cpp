// Trapping Rain Water

int maxWater(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return 0;  // No water can be trapped in an empty array

    int left = 0, right = n - 1; // Two pointers
    int leftMax = 0, rightMax = 0; // Maximum heights from the left and right
    int totalWater = 0; // Total water trapped

    // Traverse the array using the two pointers
    while (left <= right) {
        if (arr[left] <= arr[right]) {
            // Process the left pointer
            if (arr[left] >= leftMax) {
                leftMax = arr[left]; // Update the left max height
            } else {
                totalWater += leftMax - arr[left]; // Water trapped above current block
            }
            left++; // Move the left pointer to the right
        } else {
            // Process the right pointer
            if (arr[right] >= rightMax) {
                rightMax = arr[right]; // Update the right max height
            } else {
                totalWater += rightMax - arr[right]; // Water trapped above current block
            }
            right--; // Move the right pointer to the left
        }
    }

    return totalWater; // Return the total water trapped
}
