// Count distinct elements in every window

countDistinct(arr, k) {
    const result = []; // Store the result
    const freqMap = new Map(); // Track frequency of elements

    // Initialize the first window
    for (let i = 0; i < k; i++) {
        freqMap.set(arr[i], (freqMap.get(arr[i]) || 0) + 1);
    }
    result.push(freqMap.size); // Add the count of distinct elements in the first window

    // Slide the window across the array
    for (let i = k; i < arr.length; i++) {
        // Remove the element sliding out of the window
        const outElement = arr[i - k];
        freqMap.set(outElement, freqMap.get(outElement) - 1);
        if (freqMap.get(outElement) === 0) {
            freqMap.delete(outElement);
        }

        // Add the new element to the window
        freqMap.set(arr[i], (freqMap.get(arr[i]) || 0) + 1);

        // Add the count of distinct elements in the current window
        result.push(freqMap.size);
    }

    return result; // Return the result
}
