def generate_permutations(s, index, result):
    # Base case: If index reaches the end, add the current permutation
    if index == len(s):
        result.append(''.join(s))
        return
    
    used = set()  # Set to track characters used at this level
    
    for i in range(index, len(s)):
        if s[i] in used:  # Skip duplicates
            continue
        used.add(s[i])  # Mark the character as used
        s[index], s[i] = s[i], s[index]  # Swap
        generate_permutations(s, index + 1, result)  # Recurse
        s[index], s[i] = s[i], s[index]  # Backtrack

def find_permutation(s):
    result = []
    generate_permutations(list(s), 0, result)
    return result
