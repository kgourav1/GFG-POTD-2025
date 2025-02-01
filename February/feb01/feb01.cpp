bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index) {
    // If the entire word is matched, return true
    if (index == word.length()) {
        return true;
    }

    // Check if the current cell is out of bounds or doesn't match the current character of the word
    if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != word[index]) {
        return false;
    }

    // Temporarily mark the current cell as visited by changing its value
    char temp = mat[i][j];
    mat[i][j] = '#';

    // Explore all four possible directions
    bool found = dfs(mat, word, i + 1, j, index + 1) ||
                 dfs(mat, word, i - 1, j, index + 1) ||
                 dfs(mat, word, i, j + 1, index + 1) ||
                 dfs(mat, word, i, j - 1, index + 1);

    // Restore the original value of the cell
    mat[i][j] = temp;

    return found;
}

bool isWordExist(vector<vector<char>>& mat, string& word) {
    int n = mat.size();
    if (n == 0) return false;
    int m = mat[0].size();

    // Iterate through each cell in the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Start DFS from the current cell if it matches the first character of the word
            if (mat[i][j] == word[0] && dfs(mat, word, i, j, 0)) {
                return true;
            }
        }
    }

    // If no path matches the word, return false
    return false;
}
