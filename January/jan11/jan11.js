// Longest substring with distinct characters

function longestUniqueSubstr(s) {
    const lastSeen = new Array(26).fill(-1); // Array to store the last seen index of each character
    let maxLength = 0;                      // Result: Length of the longest substring
    let i = 0;                              // Start pointer of the sliding window

    for (let j = 0; j < s.length; j++) {
        const charIndex = s.charCodeAt(j) - 'a'.charCodeAt(0); // Map the character to the array index (0-25)

        // Move the start pointer if the character is already in the current window
        if (lastSeen[charIndex] !== -1) {
            i = Math.max(i, lastSeen[charIndex] + 1); // Ensure `i` moves forward
        }

        // Update the last seen index of the current character
        lastSeen[charIndex] = j;

        // Update the maximum length of the substring
        maxLength = Math.max(maxLength, j - i + 1);
    }

    return maxLength;
}
