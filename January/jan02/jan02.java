//Subarrays with sum K

// Function to count the number of subarrays with a sum equal to k
public int countSubarrays(int[] arr, int k) {
    // Create a HashMap to store the frequency of prefix sums
    HashMap<Integer, Integer> prefixSumMap = new HashMap<>();

    // Variable to store the count of subarrays with sum k
    int count = 0;

    // Variable to keep track of the prefix sum
    int prefixSum = 0;

    // Initialize the map with prefixSum = 0 occurring once
    // This handles cases where a subarray starting from index 0 has sum equal to k
    prefixSumMap.put(0, 1);

    // Traverse through each element in the array
    for (int num : arr) {
        // Update the prefix sum by adding the current element
        prefixSum += num;

        // Check if there exists a prefix sum such that:
        // prefixSum - (prefixSum - k) = k
        // If prefixSum - k exists in the map, it means there is a subarray with sum k
        if (prefixSumMap.containsKey(prefixSum - k)) {
            // Add the frequency of (prefixSum - k) to the count
            count += prefixSumMap.get(prefixSum - k);
        }

        // Increment the frequency of the current prefixSum in the map
        prefixSumMap.put(prefixSum, prefixSumMap.getOrDefault(prefixSum, 0) + 1);
    }

    // Return the total count of subarrays with sum equal to k
    return count;
}
