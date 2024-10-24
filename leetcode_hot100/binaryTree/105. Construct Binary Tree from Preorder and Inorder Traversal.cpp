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
    unordered_map<int, int> pos; // 用于存储中序遍历中每个元素的索引位置

    // 主函数，输入前序和中序遍历数组，返回构建的二叉树的根节点
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(); // 获取数组大小，即树的节点数
        // 通过值能找到中序遍历的坐标
        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }
        // 调用递归函数来构建二叉树，传入数组及其索引范围
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    // 递归函数用于构建二叉树
    TreeNode* dfs(vector<int>& pre, vector<int>& in, int pl, int pr, int il, int ir) {
        if (pl > pr) return NULL; // 如果当前段无元素，返回空节点

        // pre[pl] 是当前子树的根节点值，根据它在中序遍历中找到对应的索引
        int k = pos[pre[pl]] - il; // 计算中序遍历中根节点的索引与子段起始索引的差，即左子树的长度
        TreeNode* root = new TreeNode(pre[pl]); // 创建根节点

        // 递归构建左子树，左子树的前序遍历范围是 pl+1 到 pl+k，中序遍历范围是 il 到 il+k-1
        root->left = dfs(pre, in, pl + 1, pl + k, il, il + k - 1);
        // 递归构建右子树，右子树的前序遍历范围是 pl+k+1 到 pr，中序遍历范围是 il+k+1 到 ir
        root->right = dfs(pre, in, pl + k + 1, pr, il + k + 1, ir);

        return root; // 返回构建好的根节点
    }
};
