class Solution {
public:
    vector<vector<bool>> f; // 表示f[i][j]是否为回文子串
    vector<vector<string>> ans;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        int n = s.size();
        // 预处理，统计内部回文情况
        f = vector<vector<bool>> (n, vector<bool>(n)); // 不要忘了初始化f的大小
        for (int j = 0; j < n; j ++) // 先遍历的是右侧边界j
            for (int i = 0; i <= j; i ++)
                if (i == j) f[i][j] = true; // 单个字符天然是回文子串
                else if (s[i] == s[j]) {
                    if (i + 1 > j - 1 || f[i+1][j-1]) // 只有2/3个字符或者内部递归为真
                        f[i][j] = true;
                }
        dfs(s, 0);
        return ans;
    }

    void dfs(string& s, int u) {
        if (u == s.size()) ans.push_back(path); // 这里的base是u==s.size()，而不是u==s.size()-1,因为u表示的是下一个要处理的字符
        else {
            for (int i = u; i < s.size(); i ++ )
                if (f[u][i])  // 从当前u往后试不同长度的子串是否为回文子串
                {
                    path.push_back(s.substr(u, i - u + 1));
                    dfs(s, i + 1); // 注意这里是i+1，不是u+1也不是i
                    path.pop_back();
                }
        }
    }
};
