//Longest substring with distinct characters

public class Solution {
    public int longestUniqueSubstr(String s) {
        int[] lastSeen = new int[26];       // Array to store the last seen index of each character
        Arrays.fill(lastSeen, -1);         // Initialize all values to -1 (not seen yet)

        int maxLength = 0;                 // Result: Length of the longest substring
        int i = 0;                         // Start pointer of the sliding window

        for (int j = 0; j < s.length(); j++) {
            int charIndex = s.charAt(j) - 'a'; // Map the character to the array index (0-25)

            // Move the start pointer if the character is already in the current window
            if (lastSeen[charIndex] != -1) {
                i = Math.max(i, lastSeen[charIndex] + 1); // Ensure `i` moves forward
            }

            // Update the last seen index of the current character
            lastSeen[charIndex] = j;

            // Update the maximum length of the substring
            maxLength = Math.max(maxLength, j - i + 1);
        }

        return maxLength;
    }
}
