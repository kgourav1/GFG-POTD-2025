import java.util.*;

class Solution {
    public static List<Integer> kLargest(int[] arr, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(); // Min heap to store k largest elements

        for (int i = 0; i < k; i++) {
            minHeap.add(arr[i]); // Add first k elements
        }

        for (int i = k; i < arr.length; i++) {
            if (arr[i] > minHeap.peek()) { // If current element is larger than the smallest in heap
                minHeap.poll(); // Remove the smallest
                minHeap.add(arr[i]); // Insert new element
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!minHeap.isEmpty()) {
            result.add(minHeap.poll()); // Extract elements
        }

        Collections.reverse(result); // Reverse for descending order
        return result;
    }
}
