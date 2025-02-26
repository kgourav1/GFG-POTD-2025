 vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0); // Stores the maximum of minimums for each window size
        vector<int> left(n), right(n); // Stores indices of previous and next smaller elements
        stack<int> st;
    
        // Compute previous smaller element indices
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop(); // Remove elements that are greater than or equal to arr[i]
            }
            left[i] = st.empty() ? -1 : st.top(); // If stack is empty, no smaller element exists
            st.push(i); // Push current index onto the stack
        }
    
        // Clear the stack to reuse it for next smaller elements
        while (!st.empty()) st.pop();
    
        // Compute next smaller element indices
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop(); // Remove elements that are greater than or equal to arr[i]
            }
            right[i] = st.empty() ? n : st.top(); // If stack is empty, no smaller element exists
            st.push(i); // Push current index onto the stack
        }
    
        // Determine the max window size for each element and update res accordingly
        for (int i = 0; i < n; i++) {
            int maxWindow = right[i] - left[i] - 1; // Compute window size where arr[i] is the minimum
            res[maxWindow - 1] = max(res[maxWindow - 1], arr[i]);
        }
    
        // Fill remaining entries to ensure res[i] stores the maximum of minimums for all windows >= i+1
        for (int i = n - 2; i >= 0; i--) {
            res[i] = max(res[i], res[i + 1]);
        }
    
        return res;
    }
