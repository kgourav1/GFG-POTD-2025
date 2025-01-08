//Pair with given sum in a sorted array

int countPairs(vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1; // Initialize two pointers
    int count = 0; // Initialize the count of pairs

    while (left < right) {
        int sum = arr[left] + arr[right]; // Calculate the sum of the elements at the pointers

        if (sum == target) {
            // Case 1: When all elements between left and right are the same
            // Example: [1, 1, 1, 1], count pairs using combination formula nC2 = (n * (n - 1)) / 2
            if (arr[left] == arr[right]) {
                int len = right - left + 1; // Total number of elements
                count += (len * (len - 1)) / 2; // Add all possible pairs
                break; // No need to continue further as all elements are processed
            }

            // Case 2: Count duplicates on the left
            int leftCount = 1; // Initialize the count for duplicates on the left
            while (left < right && arr[left] == arr[left + 1]) {
                leftCount++; // Increment count for duplicates
                left++; // Move the left pointer
            }

            // Case 3: Count duplicates on the right
            int rightCount = 1; // Initialize the count for duplicates on the right
            while (right > left && arr[right] == arr[right - 1]) {
                rightCount++; // Increment count for duplicates
                right--; // Move the right pointer
            }

            // Add the product of leftCount and rightCount to the total count
            count += leftCount * rightCount;

            // Move both pointers inward to check for the next pair
            left++;
            right--;
        } else if (sum > target) {
            // If the sum is greater than the target, move the right pointer to reduce the sum
            right--;
        } else {
            // If the sum is less than the target, move the left pointer to increase the sum
            left++;
        }
    }

    return count; // Return the total count of pairs
}
