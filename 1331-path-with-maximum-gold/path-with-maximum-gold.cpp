class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }
        
        return maxGold;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        
        int gold = grid[i][j];
        grid[i][j] = 0; // Mark current cell as visited
        
        int maxGold = 0;
        maxGold = max(maxGold, dfs(grid, i + 1, j)); // Move down
        maxGold = max(maxGold, dfs(grid, i - 1, j)); // Move up
        maxGold = max(maxGold, dfs(grid, i, j + 1)); // Move right
        maxGold = max(maxGold, dfs(grid, i, j - 1)); // Move left
        
        grid[i][j] = gold; // Backtrack: Restore cell value
        return maxGold + gold; // Add current cell's gold to max gold
    }
};
