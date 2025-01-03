// Function to count the number of subarrays with XOR equal to k
    public long subarrayXor(int[] arr, int k) {
        // Create a HashMap to store the frequency of XOR prefix sums
        HashMap<Integer, Integer> xorMap = new HashMap<>();

        // Variable to count the number of subarrays with XOR equal to k
        long count = 0;

        // Variable to keep track of the prefix XOR value
        int prefixXor = 0;

        // Initialize the map with prefixXor = 0 occurring once
        // This handles cases where the XOR of a subarray starting from index 0 equals k
        xorMap.put(0, 1);

        // Traverse through each element in the array
        for (int num : arr) {
            // Update the prefix XOR value with the current element
            prefixXor ^= num;

            // Check if there exists a prefix XOR value such that:
            // prefixXor ^ (prefixXor ^ k) = k
            // If prefixXor ^ k exists in the map, it means there is a subarray with XOR equal to k
            if (xorMap.containsKey(prefixXor ^ k)) {
                // Add the frequency of (prefixXor ^ k) to the count
                count += xorMap.get(prefixXor ^ k);
            }

            // Increment the frequency of the current prefix XOR value in the map
            xorMap.put(prefixXor, xorMap.getOrDefault(prefixXor, 0) + 1);
        }

        // Return the total count of subarrays with XOR equal to k
        return count;
    }
