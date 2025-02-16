using System;
using System.Collections.Generic;

class Solution {
    public static List<int> kLargest(int[] arr, int k) {
        PriorityQueue<int, int> minHeap = new PriorityQueue<int, int>(); // Min heap

        for (int i = 0; i < k; i++) {
            minHeap.Enqueue(arr[i], arr[i]); // Add first k elements
        }

        for (int i = k; i < arr.Length; i++) {
            if (arr[i] > minHeap.Peek()) { // If current element is larger than the smallest in heap
                minHeap.Dequeue(); // Remove smallest
                minHeap.Enqueue(arr[i], arr[i]); // Insert new element
            }
        }

        List<int> result = new List<int>();
        while (minHeap.Count > 0) {
            result.Add(minHeap.Dequeue()); // Extract elements
        }

        result.Reverse(); // Reverse for descending order
        return result;
    }
}
