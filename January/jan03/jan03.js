//Count Subarrays with given XOR

function subarrayXor(arr, k) {
    // Create a map to store the frequency of XOR prefix sums
    const xorMap = new Map();

    // Variable to count the number of subarrays with XOR equal to k
    let count = 0;

    // Variable to keep track of the prefix XOR value
    let prefixXor = 0;

    // Initialize the map with prefixXor = 0 occurring once
    // This handles cases where the XOR of a subarray starting from index 0 equals k
    xorMap.set(0, 1);

    // Iterate through each element in the array
    for (let num of arr) {
        // Update the prefix XOR value with the current element
        prefixXor ^= num;

        // Check if there exists a prefix XOR value such that:
        // prefixXor ^ (prefixXor ^ k) = k
        // If prefixXor ^ k exists in the map, it means there is a subarray with XOR equal to k
        const targetXor = prefixXor ^ k;
        if (xorMap.has(targetXor)) {
            // Add the frequency of (prefixXor ^ k) to the count
            count += xorMap.get(targetXor);
        }

        // Update the frequency of the current prefix XOR value in the map
        xorMap.set(prefixXor, (xorMap.get(prefixXor) || 0) + 1);
    }

    // Return the total count of subarrays with XOR equal to k
    return count;
}
