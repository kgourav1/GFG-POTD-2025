using System;

public class Solution
{
    /// <summary>
    /// Counts the number of triplets in the array whose sum equals the target value.
    /// </summary>
    /// <param name="arr">The input array of integers</param>
    /// <param name="target">The target sum for the triplets</param>
    /// <returns>The count of triplets whose sum equals the target</returns>
    public int CountTriplets(int[] arr, int target)
    {
        int n = arr.Length; // Get the size of the array
        int count = 0; // Initialize the count of triplets to 0

        // Iterate over each element as the first element of the triplet
        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1; // Left pointer starts right after the current element
            int right = n - 1; // Right pointer starts at the end of the array

            // Use a two-pointer approach to find triplets
            while (left < right)
            {
                int tripletSum = arr[i] + arr[left] + arr[right]; // Calculate the sum of the current triplet

                if (tripletSum == target)
                {
                    // Case 1: All elements between `left` and `right` are the same
                    if (arr[left] == arr[right])
                    {
                        // Calculate combinations using nC2 formula
                        int length = right - left + 1;
                        count += (length * (length - 1)) / 2; // Add combinations to count
                        break; // Exit as all triplets for this range are counted
                    }

                    // Case 2: Count duplicates of the left element
                    int leftCount = 1;
                    while (left + 1 < right && arr[left] == arr[left + 1])
                    {
                        left++;
                        leftCount++;
                    }

                    // Count duplicates of the right element
                    int rightCount = 1;
                    while (right - 1 > left && arr[right] == arr[right - 1])
                    {
                        right--;
                        rightCount++;
                    }

                    // Add the product of left and right duplicates to the count
                    count += leftCount * rightCount;

                    // Move both pointers for the next potential triplet
                    left++;
                    right--;
                }
                else if (tripletSum > target)
                {
                    // If the sum is greater than the target, move the right pointer to decrease the sum
                    right--;
                }
                else
                {
                    // If the sum is less than the target, move the left pointer to increase the sum
                    left++;
                }
            }
        }

        // Return the total count of triplets with sum equal to the target
        return count;
    }
}

// Example usage
class Program
{
    static void Main()
    {
        Solution solution = new Solution();
        int[] arr = { 1, 2, 2, 2, 3, 4 };
        int target = 7;
        Console.WriteLine("Count of triplets: " + solution.CountTriplets(arr, target)); // Output: 4
    }
}
