class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int res = 0;
        // f[i][j]表示所有A[1,i]与B[1,j]公共子序列的集合最大值
        // f[0][0]默认为0
        // 当你查看f[i-1][j] 时，如果不使用 n+1 大小，你将不得不在每次访问数组前检查索引是否有效（即是否大于等于 0）。使用 n+1 使得你可以自由地访问 f[i-1][...] 或 f[...][j-1] 而不用担心越界错误，因为 i 和 j 的取值从 1 开始
        vector<vector<int>> f(n+1, vector<int>(m+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = max(f[i-1][j], f[i][j-1]);
                if (text1[i-1] == text2[j-1]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
            }
        }
        return f[n][m];
    }
};