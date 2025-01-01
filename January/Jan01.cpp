//Print Anagrams Together

// Function to group anagrams from a given list of strings
vector<vector<string>> anagrams(vector<string>& arr) {
    // Create an unordered_map to store groups of anagrams
    // The key will be the sorted version of the string
    // The value will be a vector of strings that are anagrams of that key
    unordered_map<string, vector<string>> mp;

    // Loop through each string in the input array
    for (auto str : arr) {
        // Copy the string to a temporary variable to generate its key
        string key = str;

        // Sort the string alphabetically to generate the key
        // Anagrams will have the same sorted key
        sort(key.begin(), key.end());

        // Group the original string under the sorted key in the map
        mp[key].push_back(str);
    }

    // Create a result vector to store the grouped anagrams
    vector<vector<string>> res;

    // Iterate through each entry in the map
    for (auto entry : mp) {
        // Add the vector of anagrams (value in the map) to the result
        res.push_back(entry.second);
    }

    // Return the grouped anagrams as a vector of vectors
    return res;
}

/*
Example:
Input: arr = ["eat", "tea", "tan", "ate", "nat", "bat"]
Step 1: Sorting each string to create keys:
    - "eat" -> "aet"
    - "tea" -> "aet"
    - "tan" -> "ant"
    - "ate" -> "aet"
    - "nat" -> "ant"
    - "bat" -> "abt"

Step 2: Grouping strings by their keys:
    - "aet": ["eat", "tea", "ate"]
    - "ant": ["tan", "nat"]
    - "abt": ["bat"]

Output: [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]
*/
