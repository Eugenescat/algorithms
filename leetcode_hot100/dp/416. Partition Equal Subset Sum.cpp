class Solution {
public:
    // 0-1背包问题
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto p : nums) sum += p;
        if (sum % 2) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        // 外层遍历物品，内层遍历背包容量(target)
        for (auto p : nums) {
            for (int j = target; j >= p; j--) {
                dp[j] = dp[j - p] || dp[j]; // 倒序遍历的原因：保证此时的dp[j-p]还处于未考虑当前p的情况
            }
        }
        return dp[target];
    }
};