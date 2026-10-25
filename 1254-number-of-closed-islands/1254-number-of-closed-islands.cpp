
class Solution {
    int m, n;

    bool closed(vector<vector<int>>& grid, int i, int j) {
        // Boundary check
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        // Water or already visited
        if (grid[i][j] == 1)
            return true;

        // Mark visited
        grid[i][j] = 1;

        // Check all four directions
        bool a = closed(grid, i + 1, j);
        bool b = closed(grid, i - 1, j);
        bool c = closed(grid, i, j + 1);
        bool d = closed(grid, i, j - 1);

        return a & b & c & d;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (closed(grid, i, j))
                        count++;
                }
            }
        }

        return count;
    }
};
