class Solution {
private:
    int m, n;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    bool isValid(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    }
    bool dfs(int row, int col, int k, vector<vector<char>>& board,
             string& word) {
        if (k == word.length())
            return true;
        if (!isValid(row, col) || board[row][col] != word[k])
            return false;
        char temp = board[row][col];
        board[row][col] = '#';
        for (int i = 0; i < 4; i++) {
            int nR = row + dr[i];
            int nC = col + dc[i];
            if (dfs(nR, nC, k + 1, board, word))
                return true;
        }
        board[row][col] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return true;
        char first = word[0];
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == first) {
                    if (dfs(i, j, 0, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};