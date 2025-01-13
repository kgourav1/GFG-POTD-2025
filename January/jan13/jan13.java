
public class Solution {
    // Container With Most Water
    public int maxWater(int[] arr) {
        int area = 0; // Variable to store the maximum water area
        int left = 0, right = arr.length - 1; // Two pointers: left and right

        // Traverse the array with two pointers
        while (left < right) {
            int h = Math.min(arr[left], arr[right]); // Calculate the height of the container
            int w = right - left;                   // Calculate the width of the container
            area = Math.max(area, h * w);           // Update the maximum area if the current area is larger

            // Move the pointers based on the heights
            if (arr[left] > arr[right]) {
                right--;  // Move the right pointer left if the right height is smaller
            } else {
                left++;   // Move the left pointer right if the left height is smaller or equal
            }
        }

        return area; // Return the maximum water area found
    }
}
