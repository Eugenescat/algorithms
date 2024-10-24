/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        // 用二进制来表示状态
        int state = 0;
        if (root == p) state |= 1;
        if (root == q) state |= 2;
        state |= dfs(root->left, p, q);
        state |= dfs(root->right, p, q);
        if (state == 3 && !ans) ans = root; // 注意如果之前已经查到ans了，不能覆盖它
        return state;
    }
};