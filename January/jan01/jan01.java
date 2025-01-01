//Print Anagrams Together

// Function to group anagrams from a given list of strings

public ArrayList<ArrayList<String>> anagrams(String[] arr) {
    // Create a HashMap to group anagrams
    // Key: Sorted version of the string
    // Value: List of strings that are anagrams of the key
    HashMap<String, ArrayList<String>> map = new HashMap<>();

    // Iterate through each string in the input array
    for (String str : arr) {
        // Convert the string to a character array for sorting
        char[] charArray = str.toCharArray();

        // Sort the character array to generate the key
        Arrays.sort(charArray);

        // Convert the sorted character array back to a string
        String key = new String(charArray);

        // If the key is not already in the map, add it with an empty list
        map.putIfAbsent(key, new ArrayList<>());

        // Add the original string to the list associated with the key
        map.get(key).add(str);
    }

    // Create the result list to store grouped anagrams
    ArrayList<ArrayList<String>> result = new ArrayList<>();

    // Add each group of anagrams from the map to the result
    for (ArrayList<String> group : map.values()) {
        result.add(group);
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
