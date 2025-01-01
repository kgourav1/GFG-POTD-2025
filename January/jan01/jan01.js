//Print Anagrams Together

// Function to group anagrams from a given list of strings
anagrams(arr) {
    // Create an object to store groups of anagrams
    // Key: Sorted version of the string
    // Value: Array of strings that are anagrams of that key
    const anagramMap = {};

    // Iterate through each string in the input array
    arr.forEach(word => {
        // Sort the characters in the word to generate the key
        const key = word.split('').sort().join('');

        // If the key doesn't exist in the map, initialize it with an empty array
        if (!anagramMap[key]) {
            anagramMap[key] = [];
        }

        // Add the original word to the array corresponding to the key
        anagramMap[key].push(word);
    });

    // Return the values from the map, which are the grouped anagrams
    return Object.values(anagramMap);
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
