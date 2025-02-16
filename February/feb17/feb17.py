import heapq

def kLargest(arr, k):
    minHeap = arr[:k]  # Take the first k elements
    heapq.heapify(minHeap)  # Convert to a min heap

    for num in arr[k:]:
        if num > minHeap[0]:  # If current element is larger than the smallest in heap
            heapq.heappop(minHeap)  # Remove smallest
            heapq.heappush(minHeap, num)  # Insert new element

    return sorted(minHeap, reverse=True)  # Return in descending order
