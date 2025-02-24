 vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n); // Stores the span for each element
        stack<int> st; // Monotonic stack to track indices

        // Traverse the array from left to right
        for (int i = 0; i < n; i++) {
            // Remove elements from the stack that are smaller or equal to arr[i]
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack is empty, it means no greater element on the left, so span is i+1
            span[i] = st.empty() ? (i + 1) : (i - st.top());

            // Push current index onto the stack
            st.push(i);
        }

        return span;
    }
