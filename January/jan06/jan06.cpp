//Sum Pair closest to target

vector<int> sumClosest(std::vector<int>& arr, int target) {
    // Step 1: Sort the array to use the two-pointer technique effectively
    std::sort(arr.begin(), arr.end());

    int n = arr.size();           // Size of the array
    int closestDiff = INT_MAX;    // Tracks the smallest difference between sum and target
    std::vector<int> result;      // Stores the closest pair of numbers

    // Step 2: Initialize two pointers
    int left = 0;                 // Points to the beginning of the array
    int right = n - 1;            // Points to the end of the array

    // Step 3: Use a loop to traverse the array with the two pointers
    while (left < right) {
        // Calculate the sum of the elements at the two pointers
        int sum = arr[left] + arr[right];

        // Calculate the absolute difference between the sum and the target
        int diff = std::abs(sum - target);

        // Step 4: Check if the current pair is closer to the target
        // Condition 1: Update if the current difference is smaller
        // Condition 2: If the difference is the same, choose the pair with a larger range
        if (diff < closestDiff || 
            (diff == closestDiff && (arr[right] - arr[left]) > (result.empty() ? 0 : result[1] - result[0]))) {
            closestDiff = diff;          // Update the smallest difference
            result = {arr[left], arr[right]}; // Update the closest pair
        }

        // Step 5: Adjust the pointers based on the current sum
        if (sum < target) {
            // If the sum is less than the target, move the left pointer to the right
            left++;
        } else if (sum > target) {
            // If the sum is greater than the target, move the right pointer to the left
            right--;
        } else {
            // If the sum is exactly equal to the target, break the loop
            // This is the closest possible pair
            break;
        }
    }

    // Step 6: Return the closest pair
    return result;
}
