class Solution {
private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& ans,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            // Check if the column or either diagonal is under attack in O(1)
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue;
            }

            // Place queen
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

            // Recurse
            backtrack(row + 1, n, board, ans, cols, diag1, diag2);

            // Backtrack
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        // Trackers for columns and the 2N-1 diagonals
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false); // row - col + n - 1
        vector<bool> diag2(2 * n - 1, false); // row + col

        backtrack(0, n, board, ans, cols, diag1, diag2);
        return ans;
    }
};