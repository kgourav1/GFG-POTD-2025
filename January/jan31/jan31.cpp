class Solution {
public:
    // Check if placing 'val' at (row, col) is valid
    bool isValid(vector<vector<int>> &grid, int row, int col, int val) {
        for (int i = 0; i < 9; i++) {
            if (grid[row][i] == val) return false; // Check row
            if (grid[i][col] == val) return false; // Check column
            if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false; // Check 3x3 box
        }
        return true;
    }

    // Backtracking function to solve Sudoku
    bool solve(vector<vector<int>> &grid) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (grid[row][col] == 0) { // Empty cell found
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(grid, row, col, num)) { // Check validity
                            grid[row][col] = num; // Place number
                            if (solve(grid)) return true; // Recur to solve next
                            grid[row][col] = 0; // Backtrack if solution not found
                        }
                    }
                    return false; // No valid number found, backtrack
                }
            }
        }
        return true; // Sudoku solved
    }

    // Function to solve the Sudoku
    void solveSudoku(vector<vector<int>> &grid) {
        solve(grid);
    }
};
