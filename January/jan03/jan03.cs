// Function to count the number of subarrays with XOR equal to k

public long SubarrayXor(int[] arr, int k)
{
    // Dictionary to store the frequency of XOR prefix sums
    Dictionary<int, int> xorMap = new Dictionary<int, int>();

    // Variable to count the number of subarrays with XOR equal to k
    long count = 0;

    // Variable to keep track of the prefix XOR value
    int prefixXor = 0;

    // Initialize the dictionary with prefixXor = 0 occurring once
    // This handles cases where the XOR of a subarray starting from index 0 equals k
    xorMap[0] = 1;

    // Traverse through each element in the array
    foreach (int num in arr)
    {
        // Update the prefix XOR value with the current element
        prefixXor ^= num;

        // Check if there exists a prefix XOR value such that:
        // prefixXor ^ (prefixXor ^ k) = k
        // If prefixXor ^ k exists in the dictionary, it means there is a subarray with XOR equal to k
        if (xorMap.ContainsKey(prefixXor ^ k))
        {
            // Add the frequency of (prefixXor ^ k) to the count
            count += xorMap[prefixXor ^ k];
        }

        // Increment the frequency of the current prefix XOR value in the dictionary
        if (!xorMap.ContainsKey(prefixXor))
        {
            xorMap[prefixXor] = 0;
        }
        xorMap[prefixXor]++;
    }

    // Return the total count of subarrays with XOR equal to k
    return count;
}
