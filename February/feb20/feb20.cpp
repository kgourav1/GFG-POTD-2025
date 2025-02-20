vector<double> getMedian(vector<int> &arr) {
    vector<double> medians;  // To store the median after each insertion
    priority_queue<int> maxHeap;  // Max heap for the smaller half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min heap for the larger half

    // Iterate through the array and insert elements one by one
    for (int num : arr) {
        // Insert into the appropriate heap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps to maintain the size difference at most 1
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Compute the median
        if (maxHeap.size() == minHeap.size()) {
            medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
        } else if (maxHeap.size() > minHeap.size()) {
            medians.push_back(maxHeap.top());
        } else {
            medians.push_back(minHeap.top());
        }
    }

    return medians;  // Return the list of medians after each insertion
}
