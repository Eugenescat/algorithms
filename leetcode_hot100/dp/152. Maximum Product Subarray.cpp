class Solution {
public:
    // 因为存在负数，不能直接用简单的“以nums[i]结尾的乘积最大的子数组“dp来做
    int maxProduct(vector<int>& nums) {
        vector<int> f(nums); // f:以nums[i]结尾的乘积最大的子数组
        vector<int> g(nums); // g:以nums[i]结尾的乘积最小的子数组
        int res = lower[0] = upper[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) { // 从1开始
            if (nums[i] > 0) {
                f[i] = max(f[i], nums[i]*f[i-1]);
                g[i] = min(g[i], nums[i]*g[i-1]);
            }
            else {
                f[i] = max(f[i], nums[i]*g[i-1]);
                g[i] = min(g[i], nums[i]*f[i-1]);
            }
            res = max(res, f[i]);
        }
        return res;
    }
};