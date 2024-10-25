class Solution {
public:
    vector<int> path;
    vector<bool> st;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        path = vector<int>(nums.size());
        st = vector<bool>(nums.size());

        dfs(nums, 0); // 目前path的长度

        return res;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (st[i]) continue;
            path[u] = nums[i]; // 注意这里不能用path.push_back(...)，因为之前已经初始化了path的大小，用puth_back会错误地往初始大小之后追加
            st[i] = true;
            dfs(nums, u + 1);
            st[i] = false;
        }
    }
};