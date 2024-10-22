class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pre(n + 2, 1);
        vector<int> tail(n + 2, 1);
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
            tail[n - i + 1] = tail[n - i + 2] * nums[n - i];
        }
        for (int i = 1; i <= n; i++) res[i - 1] = pre[i - 1] * tail[i + 1];
        return res;
    }
};