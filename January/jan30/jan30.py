class Solution:
    def fillSolution(self, ans, board, n):
        temp = []
        for col in range(n):
            for row in range(n):
                if board[row][col] == 1:
                    temp.append(row + 1)  # Store the row index (1-based) of the queen in this column
                    break
        ans.append(temp)  # Add this valid configuration to the answer

    def solve(self, col, n, board, ans, leftRow, upperDiagonal, lowerDiagonal):
        if col == n:  # Base case: All queens placed
            self.fillSolution(ans, board, n)
            return

        for row in range(n):
            if leftRow[row] == 0 and lowerDiagonal[row + col] == 0 and upperDiagonal[n - 1 - row + col] == 0:
                board[row][col] = 1  # Place queen
                leftRow[row] = 1
                lowerDiagonal[row + col] = 1
                upperDiagonal[n - 1 - row + col] = 1

                self.solve(col + 1, n, board, ans, leftRow, upperDiagonal, lowerDiagonal)
                
                board[row][col] = 0  # Backtrack
                leftRow[row] = 0
                lowerDiagonal[row + col] = 0
                upperDiagonal[n - 1 - row + col] = 0

    def nQueen(self, n):
        board = [[0] * n for _ in range(n)]  # Initialize chess board
        ans = []  # Store all valid solutions
        leftRow = [0] * n  # Track occupied rows
        upperDiagonal = [0] * (2 * n - 1)  # Track occupied upper diagonals
        lowerDiagonal = [0] * (2 * n - 1)  # Track occupied lower diagonals

        self.solve(0, n, board, ans, leftRow, upperDiagonal, lowerDiagonal)
        return ans

