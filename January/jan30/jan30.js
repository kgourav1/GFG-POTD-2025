class Solution {
    fillSolution(ans, board, n) {
        let temp = [];
        for (let col = 0; col < n; col++) {
            for (let row = 0; row < n; row++) {
                if (board[row][col] === 1) {
                    temp.push(row + 1);
                    break;
                }
            }
        }
        ans.push(temp);
    }

    solve(col, n, board, ans, leftRow, upperDiagonal, lowerDiagonal) {
        if (col === n) {
            this.fillSolution(ans, board, n);
            return;
        }

        for (let row = 0; row < n; row++) {
            if (!leftRow[row] && !lowerDiagonal[row + col] && !upperDiagonal[n - 1 - row + col]) {
                board[row][col] = 1;
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 - row + col] = 1;

                this.solve(col + 1, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);
                
                board[row][col] = 0;
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 - row + col] = 0;
            }
        }
    }

    nQueen(n) {
        let board = Array.from({ length: n }, () => Array(n).fill(0));
        let ans = [];
        let leftRow = Array(n).fill(0);
        let upperDiagonal = Array(2 * n - 1).fill(0);
        let lowerDiagonal = Array(2 * n - 1).fill(0);

        this.solve(0, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
}
