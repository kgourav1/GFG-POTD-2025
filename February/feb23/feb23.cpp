vector<int> nextLargerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1); // Initialize result array with -1 (default if no greater element exists)
    stack<int> stk; // Monotonic stack to store elements in decreasing order

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack until we find a greater element
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }

        // If stack is not empty, then the top element is the next greater element
        if (!stk.empty()) {
            ans[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(arr[i]);
    }

    return ans;
}
