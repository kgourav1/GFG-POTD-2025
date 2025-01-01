//Subarrays with sum K

// Function to count the number of subarrays with a sum equal to k
int countSubarrays(vector<int> &arr, int k) {
    // Create an unordered_map to store the frequency of prefix sums
    unordered_map<int, int> mp;

    // Variable to store the count of subarrays with sum k
    int count = 0;

    // Variable to keep track of the prefix sum
    int prefixSum = 0;

    // Initialize the map with prefixSum = 0 occurring once
    // This is to handle the case where the subarray starting from index 0 has sum equal to k
    mp[0] = 1;

    // Traverse through each element in the array
    for (auto num : arr) {
        // Update the prefix sum by adding the current element
        prefixSum += num;

        // Check if there exists a prefix sum such that:
        // prefixSum - (prefixSum - k) = k
        // In simpler terms, if prefixSum - k exists in the map, it means there is a subarray with sum k
        if (mp.find(prefixSum - k) != mp.end()) {
            // Add the frequency of (prefixSum - k) to the count
            count += mp[prefixSum - k];
        }

        // Increment the frequency of the current prefixSum in the map
        mp[prefixSum]++;
    }

    // Return the total count of subarrays with sum equal to k
    return count;
}
