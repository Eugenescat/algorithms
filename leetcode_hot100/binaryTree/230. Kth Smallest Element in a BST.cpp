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
    // 思路：写个中序遍历，找到遍历的第k个数
    int n, res;
    int kthSmallest(TreeNode* root, int k) {
        n = k;
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode* root, int k) {
        if (!root) return;
        dfs(root->left, k);
        if (res) return;

        // 判断当前节点是否是第k个
        n++;
        if (n == k) {
            res = root->val;
            return;
        }

        dfs(root->right, k);
    }
};