class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // f[i]表示选了i，g[i]表示不选i时最大的金额
        // 用1~n来表示所有房屋，所以需要开n+1大小的数组
        vector<int> f(n+1), g(n+1);
        for (int i = 1; i <= n; i ++) {
            f[i] = g[i-1] + nums[i-1]; // 注意第i个房屋里的金额是nums[i-1]，不是nums[i]
            g[i] = max(g[i-1], f[i-1]);
        }
        return max(f[n], g[n]);
    }
};