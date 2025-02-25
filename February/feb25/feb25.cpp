int getMaxArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;  // Stack to store indices
    vector<int> left(n), right(n);

    // Compute the nearest smaller element to the left
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        left[i] = st.empty() ? 0 : st.top() + 1; // If no smaller element, start from index 0
        st.push(i);
    }

    // Clear the stack for reuse
    while (!st.empty()) st.pop();

    // Compute the nearest smaller element to the right
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n - 1 : st.top() - 1; // If no smaller element, end at last index
        st.push(i);
    }

    // Compute the maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] + 1; // Width of the rectangle
        maxArea = max(maxArea, heights[i] * width);
    }

    return maxArea;
}
