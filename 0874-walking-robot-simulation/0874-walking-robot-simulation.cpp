class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obs;

        for (auto &p : obstacles) {
            obs.insert({p[0], p[1]});
        }

        int x = 0, y = 0;
        int dir = 0; // 0 = North, 1 = East, 2 = South, 3 = West

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int ans = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            }
            else if (cmd == -2) {
                dir = (dir + 3) % 4;
            }
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (obs.count({nx, ny}))
                        break;

                    x = nx;
                    y = ny;

                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};