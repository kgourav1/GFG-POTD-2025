void generatePermutations(string &s, vector<string> &result, int index) {
    // Base case: If the index reaches the end of the string, add the current permutation to the result
    if (index == s.size()) {
        result.push_back(s);
        return;
    }
    
    unordered_set<char> used; // Set to track characters that have already been swapped at this level
    
    for (int i = index; i < s.size(); i++) {
        // Skip if the character has already been used at this recursion level
        if (used.find(s[i]) != used.end()) continue;

        used.insert(s[i]);       // Mark the character as used
        swap(s[index], s[i]);    // Swap the current character with the one at the current index
        generatePermutations(s, result, index + 1); // Recursively generate permutations for the rest of the string
        swap(s[index], s[i]);    // Backtrack by undoing the previous swap
    }
}

vector<string> findPermutation(string &s) {
    vector<string> result; // Store all unique permutations
    generatePermutations(s, result, 0); // Start generating permutations from index 0
    return result; // Return the list of unique permutations
}
