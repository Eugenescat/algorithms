class Solution {
public:
    int n ;
    vector<bool> col, dg, udg;
    vector<vector<string>> ans;
    vector<string> path;

    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(2 * n); // 对角线长度为2n-1（根号2?）
        path = vector<string>(n, string(n, '.'));

        dfs(0); // 本质上是遍历row 从0到n-1
        return ans;
    }

    void dfs(int u) {
        if (u == n) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < n; i ++) {
            if (!col[i] && !dg[u - i + n] && !udg[u + i]) {
                col[i] = dg[u - i + n] = udg[u + i] = true;
                path[u][i] = 'Q';
                dfs(u + 1);
                path[u][i] = '.';
                col[i] = dg[u - i + n] = udg[u + i] = false;
            }
        }
    }
};