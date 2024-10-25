typedef pair<int, int> PII;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        queue<PII> q;
        // 将初始时刻所有已腐烂的橘子位置入队
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] == 2)
                    q.push({i, j});

        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

        int res = 0;
        // 如果队列非空，将结果减一，这是因为最后一轮的扩散不会增加分钟数
        // 因为，最后一轮的扩散是指当队列中的最后一组橘子腐烂时，它们虽然腐烂了相邻的橘子，但因为没有更多的未腐烂橘子需要在下一分钟内腐烂，所以这个扩散动作实际上没有导致时间增加。
        if (q.size()) res -- ;
        while (q.size()) {
            res ++ ;
            int sz = q.size(); // 当前队列大小，即当前轮需要处理的橘子数量
            while (sz -- ) {
                auto t = q.front(); // 取出队列首的腐烂橘子
                q.pop();
                for (int i = 0; i < 4; i ++ ) {
                    int x = t.first + dx[i], y = t.second + dy[i];
                    // 检查边界条件和是否可以传播腐烂
                    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != 1)
                        continue;
                    g[x][y] = 2; // 传播腐烂
                    q.push({x, y}); // 将新腐烂的橘子加入队列
                }
            }
        }

        // 检查是否还有新鲜橘子存在
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] == 1)
                    return -1; // 如果有新鲜橘子未被腐烂，返回-1
                    
        return res;
    }
};