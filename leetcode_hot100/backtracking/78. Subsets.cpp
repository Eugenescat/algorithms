class Solution {
public:
    // 非回溯算法，使用二进制迭代
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < 1 << n; i ++) // 遍历2^n种可能
        {
            vector<int> path;
            for (int j = 0; j < n; j ++)
                if (i >> j & 1) // 如果该种可能性的第j位为1
                    path.push_back(nums[j]);
            res.push_back(path);
        }
        return res;
    }
};