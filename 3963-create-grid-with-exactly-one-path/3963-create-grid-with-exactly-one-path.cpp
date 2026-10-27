
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string blockedRow(n, '#');
        vector<string> grid(m, blockedRow);

        for (int col = 0; col < n; col++) {
            grid[0][col] = '.';
        }

        for (int row = 0; row < m; row++) {
            grid[row][n - 1] = '.';
        }

        return grid;
    }
};
