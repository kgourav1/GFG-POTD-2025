function generatePermutations(s, index, result) {
    // Base case: If index reaches the end, add the current permutation
    if (index === s.length) {
        result.push(s.join(""));
        return;
    }

    const used = new Set(); // Set to track characters used at this level

    for (let i = index; i < s.length; i++) {
        if (used.has(s[i])) continue; // Skip duplicates
        used.add(s[i]); // Mark the character as used
        [s[index], s[i]] = [s[i], s[index]]; // Swap
        generatePermutations(s, index + 1, result); // Recurse
        [s[index], s[i]] = [s[i], s[index]]; // Backtrack
    }
}

function findPermutation(s) {
    const result = [];
    generatePermutations([...s], 0, result);
    return result;
}

