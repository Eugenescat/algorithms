class Solution {
public:
    // 思路：dp:以a[i]结尾的最长递增子序列
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        vector<int> dp(nums.size(), 1); // 每个字符结尾的子序列初始化为本身，也就是长度为1
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = 0; j <= i; j ++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};