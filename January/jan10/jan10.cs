// Count distinct elements in every window

public class Solution {
    public List<int> countDistinct(int[] arr, int k) {
        List<int> result = new List<int>(); // Store the result
        Dictionary<int, int> freqMap = new Dictionary<int, int>(); // Track frequency of elements

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            if (freqMap.ContainsKey(arr[i])) {
                freqMap[arr[i]]++;
            } else {
                freqMap[arr[i]] = 1;
            }
        }
        result.Add(freqMap.Count); // Add the count of distinct elements in the first window

        // Slide the window across the array
        for (int i = k; i < arr.Length; i++) {
            // Remove the element sliding out of the window
            freqMap[arr[i - k]]--;
            if (freqMap[arr[i - k]] == 0) {
                freqMap.Remove(arr[i - k]);
            }

            // Add the new element to the window
            if (freqMap.ContainsKey(arr[i])) {
                freqMap[arr[i]]++;
            } else {
                freqMap[arr[i]] = 1;
            }

            // Add the count of distinct elements in the current window
            result.Add(freqMap.Count);
        }

        return result; // Return the result
    }
}
