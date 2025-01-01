//Print Anagrams Together


def anagrams(self, arr):
    '''
    arr: list of words
    return: list of groups of anagrams
    '''

    # Dictionary to store groups of anagrams
    # Key: Sorted version of the string
    # Value: List of strings that are anagrams of that key
    anagram_map = {}

    # Iterate through each word in the input list
    for word in arr:
        # Sort the word alphabetically to generate the key
        # Convert the word to a sorted string
        key = ''.join(sorted(word))

        # If the key doesn't exist in the dictionary, initialize with an empty list
        if key not in anagram_map:
            anagram_map[key] = []

        # Append the original word to the list corresponding to the key
        anagram_map[key].append(word)

    # Create a result list to store the grouped anagrams
    # Extract the values (list of anagrams) from the dictionary
    result = list(anagram_map.values())

    # Return the result as a list of lists
    return result

'''
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
'''
