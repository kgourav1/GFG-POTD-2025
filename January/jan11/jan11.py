# Longest substring with distinct characters

def longestUniqueSubstr(self, s: str) -> int:
    last_seen = [-1] * 26  # Array to store the last seen index of each character
    max_length = 0         # Result: Length of the longest substring
    i = 0                  # Start pointer of the sliding window

    for j in range(len(s)):
        char_index = ord(s[j]) - ord('a')  # Map the character to the array index (0-25)

        # Move the start pointer if the character is already in the current window
        if last_seen[char_index] != -1:
            i = max(i, last_seen[char_index] + 1)  # Ensure `i` moves forward

        # Update the last seen index of the current character
        last_seen[char_index] = j

        # Update the maximum length of the substring
        max_length = max(max_length, j - i + 1)

    return max_length
