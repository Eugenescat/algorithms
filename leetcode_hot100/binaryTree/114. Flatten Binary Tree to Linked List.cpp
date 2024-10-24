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
    void flatten(TreeNode* root) {
        while (root) {
            auto p = root->left;
            if (p) {
                // 找到右链的底端
                while (p->right) p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = NULL; // 不要忘记清空左侧
            }
            root = root->right;
        }
    }
};