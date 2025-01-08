// Function to count the number of possible triangles.
int countTriangles(vector<int>& arr) {
    // Step 1: Sort the array in non-decreasing order.
    // Sorting ensures that for any indices i, j, k with i < j < k,
    // the array satisfies the triangle inequality condition.
    sort(arr.begin(), arr.end());

    // Initialize the triangle count to zero.
    int count = 0;

    // Step 2: Iterate from the end of the array to fix the largest side of the triangle.
    for (int k = arr.size() - 1; k >= 2; k--) {
        // Use two pointers to find all pairs (i, j) such that arr[i] + arr[j] > arr[k].
        int i = 0;       // Start pointer.
        int j = k - 1;   // End pointer, just before the fixed side arr[k].

        // Step 3: Use the two-pointer technique to find valid pairs.
        while (i < j) {
            // Check if the sum of arr[i] and arr[j] is greater than the largest side arr[k].
            if (arr[i] + arr[j] > arr[k]) {
                // If the condition is satisfied, all pairs between i and j are valid.
                // This is because the array is sorted, so all elements from i to j-1
                // will also form valid triangles with arr[k].
                count += (j - i); // Add all valid pairs.
                j--; // Move the end pointer left to check for other combinations.
            } else {
                // If the sum is not greater than arr[k], move the start pointer right.
                // This increases the sum of the current pair to try meeting the condition.
                i++;
            }
        }
    }

    // Step 4: Return the total count of triangles found.
    return count;
}
