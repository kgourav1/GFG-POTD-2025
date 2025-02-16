vector<int> kLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap to store the k largest elements

    // Insert the first k elements into the heap
    for (int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }

    // Process the rest of the elements
    for (int i = k; i < arr.size(); i++) {
        if (arr[i] > minHeap.top()) { // If current element is larger than the smallest in heap
            minHeap.pop(); // Remove the smallest
            minHeap.push(arr[i]); // Insert the new element
        }
    }

    vector<int> result(k); // Array to store the result
    for (int i = k - 1; i >= 0; i--) {
        result[i] = minHeap.top(); // Store elements in decreasing order
        minHeap.pop();
    }

    return result; // Return the final k largest elements in decreasing order
}
