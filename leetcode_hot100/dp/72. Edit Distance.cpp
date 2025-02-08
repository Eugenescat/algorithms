class Solution {
public:
    const int INF = 1e8;
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> f(n+1, vector<int>(m+1, INF));

        // 相当于其他题目的f[0][0] = 0这种
        for (int i = 0; i <= n; i++) f[i][0] = i;
        for (int i = 0; i <= m; i++) f[0][i] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // 处理了插入和删除的情况
                f[i][j] = min(f[i-1][j], f[i][j-1]) + 1;
                // 处理修改(包括Ai和Bj刚好相等不需要修改)的情况
                int offset = a[i-1] != b[j-1];
                f[i][j] = min(f[i][j], f[i-1][j-1] + offset);
            }
        }
        return f[n][m];
    }
};