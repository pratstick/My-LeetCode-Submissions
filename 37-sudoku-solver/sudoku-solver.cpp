class Solution {
private:
    // Arrays of bitmasks to store the state of rows, columns, and 3x3 boxes
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

    bool solve(vector<vector<char>>& board, int r, int c) {
        // If we reach row 9, the entire board is solved
        if (r == 9) return true;
        // Move to the next row if we finish the current column
        if (c == 9) return solve(board, r + 1, 0); // Typo protection: r + 1, 0
        // Skip already filled cells
        if (board[r][c] != '.') return solve(board, r, c + 1);

        int boxIdx = (r / 3) * 3 + (c / 3);

        for (int digit = 1; digit <= 9; digit++) {
            int mask = 1 << digit;
            
            // O(1) validation check using bitwise AND
            if (!(rows[r] & mask) && !(cols[c] & mask) && !(boxes[boxIdx] & mask)) {
                // Place digit (Set the bits)
                board[r][c] = (char)(digit + '0');
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIdx] |= mask;

                if (solve(board, r, c + 1)) return true;

                // Backtrack (Clear the bits)
                board[r][c] = '.';
                rows[r] &= ~mask;
                cols[c] &= ~mask;
                boxes[boxIdx] &= ~mask;
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        // Step 1: Initialize masks with the existing board setup
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '0';
                    int mask = 1 << digit;
                    int boxIdx = (i / 3) * 3 + (j / 3);
                    
                    rows[i] |= mask;
                    cols[j] |= mask;
                    boxes[boxIdx] |= mask;
                }
            }
        }
        // Step 2: Start solving from top-left cell (0, 0)
        solve(board, 0, 0);
    }
};