class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> g(m, vector<int>(n));
        if (m == 1 || n == 1) return 1;
        g[0][0] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                g[0][j] = 1;
                g[i][0] = 1;
                g[i][j] = g[i-1][j] + g[i][j-1];
            }
        }
        return g[m-1][n-1];
    }
};