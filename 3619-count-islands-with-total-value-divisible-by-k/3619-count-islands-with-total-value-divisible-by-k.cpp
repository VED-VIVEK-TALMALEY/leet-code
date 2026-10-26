#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int validIslands = 0;
        
        // Directions for moving 4-directionally
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find land (value > 0), trigger a BFS traversal
                if (grid[i][j] > 0) {
                    long long islandSum = 0;
                    queue<pair<int, int>> q;
                    
                    q.push({i, j});
                    islandSum += grid[i][j];
                    grid[i][j] = 0; // Mark as visited by resetting cell to 0
                    
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        
                        for (auto& dir : dirs) {
                            int nr = r + dir.first;
                            int nc = c + dir.second;
                            
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                islandSum += grid[nr][nc];
                                grid[nr][nc] = 0; // Mark visited
                                q.push({nr, nc});
                            }
                        }
                    }
                    
                    if (islandSum % k == 0) {
                        validIslands++;
                    }
                }
            }
        }
        
        return validIslands;
    }
};