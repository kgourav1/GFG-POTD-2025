// Function to count the number of triplets in the array whose sum equals the target value
public int countTriplets(int[] arr, int target) {
    int n = arr.length; // Get the size of the array
    int count = 0; // Initialize the count of triplets to 0

    // Iterate over each element of the array as the first element of the triplet
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;    // Left pointer starts right after the current element
        int right = n - 1;   // Right pointer starts at the end of the array

        // Perform a two-pointer approach to find triplets
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right]; // Calculate the sum of the current triplet

            // Check if the triplet sum equals the target
            if (sum == target) {
                // Case 1: All elements between `left` and `right` are the same
                if (arr[left] == arr[right]) {
                    // Calculate the number of combinations using nC2 formula
                    int length = right - left + 1;
                    count += (length * (length - 1)) / 2; // Add the combinations to the count
                    break; // Exit the loop as all triplets for this range are counted
                }

                // Case 2: Count duplicates of the left element
                int leftCount = 1; // At least one instance of the left element exists
                while (left + 1 < right && arr[left] == arr[left + 1]) {
                    left++; // Move the left pointer to count duplicates
                    leftCount++;
                }

                // Count duplicates of the right element
                int rightCount = 1; // At least one instance of the right element exists
                while (right - 1 > left && arr[right] == arr[right - 1]) {
                    right--; // Move the right pointer to count duplicates
                    rightCount++;
                }

                // Add the product of left and right duplicates to the count
                count += leftCount * rightCount;

                // Move both pointers to find the next potential triplet
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
    }

    // Return the total count of triplets with sum equal to the target
    return count;
}
