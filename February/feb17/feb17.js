function kLargest(arr, k) {
    let minHeap = new MinPriorityQueue(); // Min heap
    
    for (let i = 0; i < k; i++) {
        minHeap.enqueue(arr[i]); // Insert first k elements
    }

    for (let i = k; i < arr.length; i++) {
        if (arr[i] > minHeap.front().element) { // If current element is larger than the smallest in heap
            minHeap.dequeue(); // Remove smallest
            minHeap.enqueue(arr[i]); // Insert new element
        }
    }

    let result = [];
    while (!minHeap.isEmpty()) {
        result.push(minHeap.dequeue().element); // Extract elements
    }

    return result.reverse(); // Return in descending order
}
