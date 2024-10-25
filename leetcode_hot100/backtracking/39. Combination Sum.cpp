class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return ans;
    }

    void dfs(vector<int>& candidates, int u, int target) {
        if (target == 0) { // 凑到了target
            ans.push_back(path);
            return;
        }

        if (u == candidates.size()) return; // 凑数最终失败

        // 如果跳过当前c[u]
        dfs(candidates, u + 1, target);

        for (int i = 1; candidates[u] * i <= target; i ++) // 对当前c[u]，取0，1，2……个试试
        {
            path.push_back(candidates[u]); // 每次多添加一个c[u]
            dfs(candidates, u + 1, target - candidates[u] * i);
        }

        // 清空回退
        for (int i = 1; candidates[u] * i <= target; i ++) {
            path.pop_back();
        }
    }
};