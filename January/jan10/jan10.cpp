//Count distinct elements in every window

vector<int> countDistinct(vector<int> &arr, int k) {
    vector<int> result;                     // Store the count of distinct elements for each window
    unordered_map<int, int> freqMap;        // Map to track the frequency of elements in the current window
    int n = arr.size();                     // Length of the array

    // Initialize the first window
    for (int i = 0; i < k; i++) {
        freqMap[arr[i]]++;                  // Increment frequency of each element
    }
    result.push_back(freqMap.size());       // Add the count of distinct elements in the first window

    // Slide the window across the array
    for (int i = k; i < n; i++) {
        // Remove the element that is sliding out of the window
        freqMap[arr[i - k]]--;
        if (freqMap[arr[i - k]] == 0) {     // If frequency becomes zero, remove the element from the map
            freqMap.erase(arr[i - k]);
        }

        // Add the new element to the window
        freqMap[arr[i]]++;

        // Add the count of distinct elements in the current window to the result
        result.push_back(freqMap.size());
    }

    return result;                          // Return the result
}
