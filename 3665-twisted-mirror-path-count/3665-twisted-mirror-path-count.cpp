#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        // go[i][j][dir] stores {next_r, next_c} when moving from (i, j) in direction dir
        // dir = 0: Right, dir = 1: Down
        vector<vector<vector<pair<int, int>>>> go(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-2, -2})));

        auto getNext = [&](auto& self, int r, int c, int dir) -> pair<int, int> {
            int nr = r + (dir == 1 ? 1 : 0);
            int nc = c + (dir == 0 ? 1 : 0);

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                return {-1, -1}; // Out of bounds
            }

            if (grid[nr][nc] == 0) {
                return {nr, nc}; // Valid non-mirror cell reached
            }

            if (go[nr][nc][dir].first != -2) {
                return go[nr][nc][dir];
            }

            // Mark visited for cycle detection in reflections
            go[nr][nc][dir] = {-1, -1};

            // Mirror reflection: Right (0) becomes Down (1), Down (1) becomes Right (0)
            int next_dir = 1 - dir;
            return go[nr][nc][dir] = self(self, nr, nc, next_dir);
        };

        // Precompute jumps for all cells and directions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    go[i][j][0] = getNext(getNext, i, j, 0);
                    go[i][j][1] = getNext(getNext, i, j, 1);
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                for (int dir = 0; dir < 2; ++dir) {
                    auto [next_r, next_c] = go[i][j][dir];
                    if (next_r != -1 && next_c != -1) {
                        dp[next_r][next_c] = (dp[next_r][next_c] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};