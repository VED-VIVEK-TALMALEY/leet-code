class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 1) {
            return;
        }
        
     
        grid[r][c] = 1;
        
      
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
      
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 0) {
                    dfs(grid, i, j);
                }
            }
        }
        
       
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
};