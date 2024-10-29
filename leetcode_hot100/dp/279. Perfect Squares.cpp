class Solution {
public:
    // 完全背包
    int numSquares(int n) {
        // f[i] 表示组成整数 i 所需的最少平方数数量
        // 除了f[0]以外，其他位置初始化为较大值
        vector<int> f(n+1, n);
        // f[0] 初始化为 0，因为组成数字 0 不需要任何平方数
        f[0] = 0;
        // 如果你考虑使用平方数 j * j，那么组成 i 所需的最少平方数数量可以通过查看组成 i - j * j 所需的最少平方数数量（即 f[i - j * j]）加上这一个 j * j 来得到
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                f[i] = min(f[i], f[i - j * j] + 1);
            }
        }
        return f[n];
    }
};