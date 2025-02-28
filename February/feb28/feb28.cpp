int evaluate(vector<string>& tokens) {
        // code here
        stack<int> st;
    
        // Iterate through each token in the input array
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop top two elements for the operation
                int b = st.top(); st.pop(); // Second operand
                int a = st.top(); st.pop(); // First operand
                
                // Perform the respective operation and push the result back onto the stack
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else st.push(a / b); // Division (integer division as per problem constraints)
            } else {
                // Convert string token to integer and push onto the stack
                st.push(stoi(token));
            }
        }
        
        return st.top(); // Final result is at the top of the stack
    }
