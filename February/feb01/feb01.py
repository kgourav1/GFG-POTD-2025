def dfs(mat, word, i, j, index):
    # If the entire word is matched, return True
    if index == len(word):
        return True

    # Check if the current cell is out of bounds or doesn't match the current character of the word
    if i < 0 or i >= len(mat) or j < 0 or j >= len(mat[0]) or mat[i][j] != word[index]:
        return False

    # Temporarily mark the current cell as visited by changing its value
    temp = mat[i][j]
    mat[i][j] = '#'

    # Explore all four possible directions
    found = (dfs(mat, word, i + 1, j, index + 1) or
             dfs(mat, word, i - 1, j, index + 1) or
             dfs(mat, word, i, j + 1, index + 1) or
             dfs(mat, word, i, j - 1, index + 1))

    # Restore the original value of the cell
    mat[i][j] = temp

    return found

def isWordExist(mat, word):
    n = len(mat)
    if n == 0:
        return False
    m = len(mat[0])

    # Iterate through each cell in the matrix
    for i in range(n):
        for j in range(m):
            # Start DFS from the current cell if it matches the first character of the word
            if mat[i][j] == word[0] and dfs(mat, word, i, j, 0):
                return True

    # If no path matches the word, return False
    return False

# Example usage
mat = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']]
word = "GEEK"
print(isWordExist(mat, word))  # Output: True
