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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return dfs(root)[0];
    }

    vector<int> dfs(TreeNode* root) {
        // 1代表当前子树是BST，第二个值代表子树中的最小值，第三个值代表子树中的最大值
        vector<int> res({1, root->val, root->val});
        if (root->left) {
            auto t = dfs(root->left);
            if (!t[0] || t[2] >= root->val ) res[0] = 0;
            // 更新当前树的最小值和最大值
            res[1] = min(res[1], t[1]);
            res[2] = max(res[2], t[2]);
        }
        if (root->right) {
            auto t = dfs(root->right);
            if (!t[0] || t[1] <= root->val) res[0] = 0;
            // 更新当前树的最小值和最大值
            res[1] = min(res[1], t[1]);
            res[2] = max(res[2], t[2]);
        }
        return res;
    }
};