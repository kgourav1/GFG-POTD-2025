//Product array puzzle

class Solution {
    public int[] ProductExceptSelf(int[] arr) {
        int n = arr.Length;
        int[] res = new int[n];
        Array.Fill(res, 1);

        // Compute prefix product
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= arr[i];
        }

        // Compute suffix product and multiply with prefix product
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= arr[i];
        }

        return res;
    }
}
