/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> cnt;  // 前缀和字典，用于记录某个前缀和出现的次数
    int res = 0;

    int pathSum(TreeNode* root, int targetSum) {
        cnt[0]++;  // 初始化前缀和字典，因为前缀和为0的情况默认应该有一次，便于从根节点开始的路径计算
        dfs(root, targetSum, 0);
        return res;
    }

    void dfs(TreeNode* root, int sum, long long cur) {
        if (!root) return;
        cur += root->val;
        res += cnt[cur - sum]; // 先找之前的前缀和
        cnt[cur] ++; // 再更新哈希表状态
        dfs(root->left, sum, cur);
        dfs(root->right, sum, cur);
        cnt[cur] --; // 回溯哈希表状态
    }
};
