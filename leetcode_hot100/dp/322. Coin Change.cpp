class Solution {
public:
    // 完全背包
    int INF = 1e9;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, INF);
        f[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j ++) {
                int p = coins[j];
                if (p <= i)
                    f[i] = min(f[i], f[i - p] + 1);
            }
        }
        if (f[amount] == INF) return -1;
        return f[amount];
    }
};