class Solution {
private:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.') continue;
                for(int digit=1;digit<=9;digit++){
                    if(isValid(digit,i,j,board)){
                        board[i][j] = (char)(digit + '0');
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(int digit, int row, int col, vector<vector<char>>& board){
        int sr = (row/3) * 3;
        int sc = (col/3) * 3;
        for(int i=0;i<9;i++){
            if(board[i][col] - '0' ==digit) return false;
            if(board[row][i] - '0'==digit) return false;
            if(board[sr + i/3][sc + i%3] - '0' ==digit) return false;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};