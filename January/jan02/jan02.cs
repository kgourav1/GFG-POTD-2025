//Subarrays with sum K

public int CountSubarrays(int[] arr, int k)
{
    // Dictionary to store the frequency of prefix sums
    Dictionary<int, int> prefixSumMap = new Dictionary<int, int>();

    // Variable to store the count of subarrays with sum k
    int count = 0;

    // Variable to keep track of the prefix sum
    int prefixSum = 0;

    // Initialize the dictionary with prefixSum = 0 occurring once
    // This handles cases where a subarray starting from index 0 has sum equal to k
    prefixSumMap[0] = 1;

    // Traverse through each element in the array
    foreach (int num in arr)
    {
        // Update the prefix sum by adding the current element
        prefixSum += num;

        // Check if there exists a prefix sum such that:
        // prefixSum - (prefixSum - k) = k
        // If prefixSum - k exists in the dictionary, it means there is a subarray with sum k
        if (prefixSumMap.ContainsKey(prefixSum - k))
        {
            // Add the frequency of (prefixSum - k) to the count
            count += prefixSumMap[prefixSum - k];
        }

        // Increment the frequency of the current prefixSum in the dictionary
        if (prefixSumMap.ContainsKey(prefixSum))
        {
            prefixSumMap[prefixSum]++;
        }
        else
        {
            prefixSumMap[prefixSum] = 1;
        }
    }

    // Return the total count of subarrays with sum equal to k
    return count;
}
