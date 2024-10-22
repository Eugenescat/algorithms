class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (!matrix.size() || !matrix[0].size()) return res;
        int n = matrix.size();
        int m = matrix[0].size();

        int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

        // 表示每个格子有没有被遍历过
        vector<vector<bool>> st(n, vector<bool>(m));

        // 从左上角开始遍历，一共遍历n*m次
        for (int i = 0, x = 0, y = 0, d = 0; i < n*m; i++)
        {
            // 添加当前走过的格子
            res.push_back(matrix[x][y]);
            st[x][y] = true;

            // 走向下一个格子
            int a = x + dx[d], b = y + dy[d];
            // 如果越界了，重新走下一个方向
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b])
            {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }

        return res;
    }
};