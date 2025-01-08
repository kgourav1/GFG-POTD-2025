// Function to count the number of possible triangles
public int countTriangles(int[] arr)
{
    // Step 1: Sort the array in ascending order
    Array.Sort(arr);

    int count = 0; // Initialize the count of triangles
    int n = arr.Length; // Get the size of the array

    // Step 2: Fix the largest side of the triangle
    for (int k = n - 1; k >= 2; k--)
    {
        int i = 0;       // Start pointer
        int j = k - 1;   // End pointer (just before the fixed side)

        // Step 3: Use the two-pointer technique to find valid pairs
        while (i < j)
        {
            // Check if the sum of arr[i] and arr[j] is greater than arr[k]
            if (arr[i] + arr[j] > arr[k])
            {
                // If valid, all pairs between i and j are valid
                count += (j - i);

                // Move the end pointer left to check for other combinations
                j--;
            }
            else
            {
                // If not valid, move the start pointer right to increase the sum
                i++;
            }
        }
    }

    // Step 4: Return the total count of triangles
    return count;
}