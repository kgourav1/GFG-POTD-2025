//Print Anagrams Together

// function to find all anagram words in a list of strings in C#
public List<List<string>> anagrams(string[] arr) {
   // Dictionary to store groups of anagrams
    // Key: Sorted version of the string
    // Value: List of strings that are anagrams of that key
    Dictionary<string, List<string>> anagramMap = new Dictionary<string, List<string>>();

    // Iterate through each string in the input array
    foreach (string word in arr) {
        // Convert the string into a character array and sort it to generate the key
        char[] charArray = word.ToCharArray();
        Array.Sort(charArray);
        string key = new string(charArray);

        // If the key does not exist in the dictionary, add it with an empty list
        if (!anagramMap.ContainsKey(key)) {
            anagramMap[key] = new List<string>();
        }

        // Add the original word to the list corresponding to the key
        anagramMap[key].Add(word);
    }

    // Create the result list to store grouped anagrams
    List<List<string>> result = new List<List<string>>();

    // Add each group of anagrams from the dictionary to the result
    foreach (var group in anagramMap.Values) {
        result.Add(group);
    }

    // Return the result
    return result;
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
