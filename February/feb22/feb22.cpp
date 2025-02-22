int maxLength(string S) {
        stack<int> stk; // Stack to store indices of unmatched parentheses
        int maxLen = 0; // Stores the length of the longest valid substring

        // Push -1 to handle edge cases where the first character is a valid ')'
        stk.push(-1);

        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                // Push index of '(' to track its position
                stk.push(i);
            } else {
                // Pop last '(' index (if exists)
                stk.pop();

                if (stk.empty()) {
                    // If stack is empty, push the current index of ')'
                    // This acts as a base for the next valid substring
                    stk.push(i);
                } else {
                    // Calculate valid substring length as `current index - top index in stack`
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }

        return maxLen;
    }
