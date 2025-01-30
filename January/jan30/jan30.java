class Solution {
    public void fillSolution(List<List<Integer>> ans, int[][] board, int n) {
        List<Integer> temp = new ArrayList<>();
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                if (board[row][col] == 1) {
                    temp.add(row + 1);
                    break;
                }
            }
        }
        ans.add(temp);
    }

    public void solve(int col, int n, int[][] board, List<List<Integer>> ans, int[] leftRow, int[] upperDiagonal, int[] lowerDiagonal) {
        if (col == n) {
            fillSolution(ans, board, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 - row + col] == 0) {
                board[row][col] = 1;
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 - row + col] = 1;

                solve(col + 1, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);

                board[row][col] = 0;
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 - row + col] = 0;
            }
        }
    }

    public List<List<Integer>> nQueen(int n) {
        int[][] board = new int[n][n];
        List<List<Integer>> ans = new ArrayList<>();
        int[] leftRow = new int[n];
        int[] upperDiagonal = new int[2 * n - 1];
        int[] lowerDiagonal = new int[2 * n - 1];
        
        solve(0, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
}

