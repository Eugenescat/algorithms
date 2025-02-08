class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (!n) return 0;
        int m = grid[0].size();
        vector<vector<int>> g(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i && !j) g[i][j] = grid[i][j];
                else if (!i) g[i][j] = g[i][j-1] + grid[i][j];
                else if (!j) g[i][j] = g[i-1][j] + grid[i][j];
                else g[i][j] = min(g[i-1][j], g[i][j-1]) + grid[i][j];
            }
        }
        return g[n-1][m-1];
    }
};