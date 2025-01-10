// Count distinct elements in every window

public ArrayList<Integer> countDistinct(int arr[], int k) {
    ArrayList<Integer> result = new ArrayList<>(); // Store the result
    HashMap<Integer, Integer> freqMap = new HashMap<>(); // Track frequency of elements

    // Initialize the first window
    for (int i = 0; i < k; i++) {
        freqMap.put(arr[i], freqMap.getOrDefault(arr[i], 0) + 1);
    }
    result.add(freqMap.size()); // Add the count of distinct elements in the first window

    // Slide the window across the array
    for (int i = k; i < arr.length; i++) {
        // Remove the element sliding out of the window
        freqMap.put(arr[i - k], freqMap.get(arr[i - k]) - 1);
        if (freqMap.get(arr[i - k]) == 0) {
            freqMap.remove(arr[i - k]);
        }

        // Add the new element to the window
        freqMap.put(arr[i], freqMap.getOrDefault(arr[i], 0) + 1);

        // Add the count of distinct elements in the current window
        result.add(freqMap.size());
    }

    return result; // Return the result
}
