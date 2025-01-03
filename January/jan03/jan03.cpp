//Count Subarrays with given XOR

long subarrayXor(vector<int> &arr, int k) {
    // Create an unordered_map to store the frequency of XOR prefix sums
    unordered_map<int, int> mp;

    // Variable to count the number of subarrays with XOR equal to k
    long count = 0;

    // Variable to keep track of the prefix XOR value
    int prefixSum = 0;

    // Initialize the map with prefixSum = 0 occurring once
    // This helps handle cases where the XOR of a subarray from the start equals k
    mp[0] = 1;

    // Traverse through each element in the array
    for (auto num : arr) {
        // Update the prefix XOR value with the current element
        prefixSum ^= num;

        // Check if there exists a prefix XOR value such that:
        // prefixSum ^ (prefixSum ^ k) = k
        // If prefixSum ^ k exists in the map, it means there is a subarray with XOR equal to k
        if (mp.find(prefixSum ^ k) != mp.end()) {
            // Add the frequency of (prefixSum ^ k) to the count
            count += mp[prefixSum ^ k];
        }

        // Increment the frequency of the current prefix XOR value in the map
        mp[prefixSum]++;
    }

    // Return the total count of subarrays with XOR equal to k
    return count;
}
