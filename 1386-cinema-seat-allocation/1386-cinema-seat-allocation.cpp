class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Store reserved seats using a bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                rows[row] |= (1 << col);
            }
        }

        int ans = (n - rows.size()) * 2;

        for (auto &[row, mask] : rows) {
            bool left = true;   // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for (int seat = 2; seat <= 5; seat++) {
                if (mask & (1 << seat))
                    left = false;
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (mask & (1 << seat))
                    middle = false;
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (mask & (1 << seat))
                    right = false;
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};