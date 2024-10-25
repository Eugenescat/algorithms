class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n); // 邻接表
        vector<int> d(n); // 入度统计

        for (auto& e : edges) {
            int a = e[0], b = e[1]; // a指向b的一条边
            g[a].push_back(b);
            d[b] ++; // b的入度++
        }

        int cnt = 0;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (d[i] == 0)
                q.push(i); // 把入度为0的节点加入队列

        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt ++; // 入度为0的节点++
            for (auto i : g[t]) // （以该节点为先修课的课程）该节点的所有指向的课程入度--
                if ( -- d[i] == 0)
                    q.push(i); // 如果刚好该子节点入度减为0，加入队列
        }

        return cnt == n;
    }
};