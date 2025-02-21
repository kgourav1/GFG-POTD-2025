#include <stack>
#include <string>

class Solution {
public:
    // Function to check if the given string has balanced parentheses
    bool ispar(string s) {
        // If the length of the string is 1 or empty, it can't be balanced
        if (s.length() <= 1) {
            return false;
        }

        stack<char> stk;  // Stack to keep track of opening brackets

        // Iterate through each character in the string
        for (char ch : s) {
            // If it's an opening bracket, push it onto the stack
            if (ch == '[' || ch == '{' || ch == '(') {
                stk.push(ch);
            } 
            // If it's a closing bracket
            else {
                // If stack is empty, there's no matching opening bracket
                if (stk.empty()) {
                    return false;
                }

                // Check if the current closing bracket matches the top of the stack
                char top = stk.top();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;  // Mismatched brackets
                }

                // Pop the matched opening bracket
                stk.pop();
            }
        }

        // If the stack is empty, all brackets were matched correctly
        return stk.empty();
    }
};
