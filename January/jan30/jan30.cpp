class Solution {
private:
    // Function to store a valid board configuration in the answer list
    void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
        vector<int> temp;
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                if (board[row][col] == 1) {
                    temp.push_back(row + 1); // Store 1-based row index
                    break;
                }
            }
        }
        ans.push_back(temp);
    }

    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        int x = row, y = col;

        // Check the leftward row (same row, previous columns)
        while (y >= 0) {
            if (board[x][y] == 1) return false;
            y--;
        }

        // Check upper-left diagonal
        x = row, y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 1) return false;
            x--;
            y--;
        }

        // Check lower-left diagonal
        x = row, y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 1) return false;
            x++;
            y--;
        }

        return true; // No conflicts, it's safe to place a queen here
    }

    // Recursive function to place queens column by column
    void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans) {
        // If all queens are placed, add the solution and return
        if (col == n) {
            addSolution(ans, board, n);
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1;  // Place the queen
                solve(col + 1, n, board, ans);  // Recur for next column
                board[row][col] = 0;  // Backtrack (remove the queen)
            }
        }
    }

public:
    // Function to find all solutions to the N-Queens problem
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize board with 0s
        vector<vector<int>> ans; // To store all valid board configurations
        solve(0, n, board, ans); // Start placing queens from column 0
        return ans; // Return all valid solutions
    }
};
