class Solution {
public:
    vector<vector<char>> g; // 会修改g    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        int cnt = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j] == '1') {
                    dfs(i, j);
                    cnt ++;
                }
            }
        }
        return cnt;
    }

    void dfs(int x, int y) {
        g[x][y] = 0; // 标记为已遍历
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            // 防止数组越界，并找到和当前岛屿相连的所有岛屿1，都标为0
            if (a >= 0 && a < g.size() && b >= 0 && b < g[a].size() && g[a][b] == '1')
                dfs(a, b);
        }
    }
};