class LcaBinaryLifting {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> pa;

public:
    // 构造时传入无向边列表（节点编号从 0 开始）
    LcaBinaryLifting(vector<vector<int>>& edges) {
        n = edges.size() + 1;
        LOG = __lg(n) + 1;

        // 建图
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int x = e[0] - 1;
            int y = e[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        // 初始化
        depth.assign(n, 0);
        pa.assign(n, vector<int>(LOG, -1));

        // 第一次 DFS：填 pa[][0] 和 depth[]
        function<void(int,int)> dfs = [&](int u, int p) {
            pa[u][0] = p;
            for (int v : g[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        };
        dfs(0, -1);

        // 构建完整的 pa 表
        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                int mid = pa[u][k-1];
                pa[u][k] = (mid < 0 ? -1 : pa[mid][k-1]);
            }
        }
    }

    // 找到 node 的第 k 级祖先，若不存在返回 -1
    int get_kth_ancestor(int node, int k) {
        for (int b = 0; b < LOG && node != -1; b++) {
            if (k & (1 << b)) {
                node = pa[node][b];
            }
        }
        return node;
    }

    // 最近公共祖先
    int get_lca(int x, int y) {
        if (depth[x] < depth[y]) swap(x, y);
        // 先把 x 跳到和 y 同一深度
        x = get_kth_ancestor(x, depth[x] - depth[y]);
        if (x == y) return x;
        // 从高位往低位同时跳
        for (int k = LOG - 1; k >= 0; k--) {
            if (pa[x][k] != pa[y][k]) {
                x = pa[x][k];
                y = pa[y][k];
            }
        }
        // 此时 x 和 y 的父节点就是 LCA
        return pa[x][0];
    }

    // x 到 y 的边数距离
    int get_dis(int x, int y) {
        int w = get_lca(x, y);
        return depth[x] + depth[y] - 2 * depth[w];
    }
};

class Solution {
public:
    int const MOD = 1000000007;

    // 前提是int n >= 0
    long long qpow(long long x, int n) {
        long long res = 1;
        while (n > 0) {
            if (n % 2) res = res * x % MOD;
            x = x * x % MOD;
            n /= 2;
        }
        return res;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LcaBinaryLifting lca(edges);
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            // lca是用0～n-1表示节点
            int x = queries[i][0] - 1;
            int y = queries[i][1] - 1;
            if (x == y) ans.push_back(0);
            else ans.push_back(qpow(2, lca.get_dis(x, y) - 1) % MOD);
        }

        return ans;
    }  
};