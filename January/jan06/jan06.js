//Sum Pair closest to target

/**
 * Finds the pair of numbers in the array whose sum is closest to the target.
 * 
 * @param {number[]} arr - The input array of integers
 * @param {number} target - The target sum
 * @return {number[]} - A pair of numbers whose sum is closest to the target
 */
sumClosest(arr, target) {
    // Step 1: Sort the array in ascending order
    arr.sort((a, b) => a - b);

    // Initialize variables to track the closest difference and result pair
    let closestDiff = Infinity; // Represents the smallest difference found
    let result = []; // To store the pair with the closest sum

    // Initialize two pointers
    let left = 0; // Points to the start of the array
    let right = arr.length - 1; // Points to the end of the array

    // Step 2: Use the two-pointer technique to find the closest sum
    while (left < right) {
        // Calculate the sum of the elements at the two pointers
        let currentSum = arr[left] + arr[right];

        // Calculate the absolute difference between the current sum and the target
        let diff = Math.abs(currentSum - target);

        // Step 3: Update the result if the current pair is closer
        if (
            diff < closestDiff || 
            (diff === closestDiff && (arr[right] - arr[left]) > (result.length ? result[1] - result[0] : 0))
        ) {
            closestDiff = diff; // Update the closest difference
            result = [arr[left], arr[right]]; // Update the closest pair
        }

        // Step 4: Adjust pointers based on the current sum
        if (currentSum < target) {
            // If the sum is less than the target, move the left pointer to the right
            left++;
        } else if (currentSum > target) {
            // If the sum is greater than the target, move the right pointer to the left
            right--;
        } else {
            // If the sum is exactly the target, we've found the closest possible pair
            break;
        }
    }

    // Step 5: Return the closest pair
    return result;
}
