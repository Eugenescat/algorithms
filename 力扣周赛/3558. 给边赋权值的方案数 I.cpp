class Solution {
public:
    int const MOD = 1000000007;

    long long qpow(long long x, int n) {
        long long res = 1;
        while (n > 0) {
            if (n % 2) res = res * x % MOD;
            x = x * x % MOD;
            n /= 2;
        }
        return res;
    }

    vector<vector<int>> adj;
    // 求二叉树最大深度(按节点数）
    int maxDepth(int u, int parent) {
        int maxD = 0;
        for (int v: adj[u]) {
            if (v != parent) {
                maxD = max(maxD, maxDepth(v, u));
            }
        }
        return maxD + 1; // 当前节点1 + 子树最大节点数
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        // 把edges转化为邻接表
        int n = edges.size() + 1; // 长度为 n - 1 的二维整数数组 edges , 节点从 1 到 n 编号
        adj = vector<vector<int>>(n+1);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxLen = maxDepth(1, 0) - 1; // 边的数量是节点数-1

        return qpow(2, maxLen - 1) % MOD;
    }
};