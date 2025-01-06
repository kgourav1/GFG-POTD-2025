
//Sum Pair closest to target

    public List<Integer> sumClosest(int[] arr, int target) {
        // Step 1: Sort the array to enable two-pointer technique
        Arrays.sort(arr);

        // Variables to track the closest difference and the result pair
        int closestDiff = Integer.MAX_VALUE; // Smallest difference between sum and target
        List<Integer> result = new ArrayList<>(); // To store the closest pair

        // Initialize two pointers
        int left = 0; // Start pointer
        int right = arr.length - 1; // End pointer

        // Step 2: Traverse the array using the two-pointer approach
        while (left < right) {
            // Calculate the sum of the elements at the two pointers
            int sum = arr[left] + arr[right];

            // Calculate the absolute difference between the sum and the target
            int diff = Math.abs(sum - target);

            // Step 3: Update the closest pair if a better pair is found
            if (diff < closestDiff || 
                (diff == closestDiff && (arr[right] - arr[left]) > (result.isEmpty() ? 0 : result.get(1) - result.get(0)))) {
                closestDiff = diff; // Update the smallest difference
                result = Arrays.asList(arr[left], arr[right]); // Update the result pair
            }

            // Step 4: Adjust the pointers based on the current sum
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

        // Step 5: Return the closest pair as a list
        return result;
    }
