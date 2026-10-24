class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int i = 0, j = 0;
        int pi = 0, pj = 0;

        while (i >= 0 && i < n && j >= 0 && j < m
               && grid[i][j] != '#') {
            char dir = grid[i][j];
            grid[i][j] = '#';

            pi = i;
            pj = j;

            if (dir == 'L') j--;
            else if (dir == 'R') j++;
            else if (dir == 'U') i--;
            else i++;
        }

        return {pi, pj};
    }
};