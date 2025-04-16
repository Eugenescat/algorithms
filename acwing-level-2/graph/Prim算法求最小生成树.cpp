#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N]; // 某个点和集合的距离
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        // 找到集合外距离集合最近的点
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return INF; // 存在一个与集合没有连接的点，最小生成树失败。但前提是i并不是第一个点，因为当i=0时，此时集合还是空的，dist[i]为初始化的INF，是正常的
        if (i) res += dist[t]; // 当 i == 0 时，我们正在选择生成树的第一个点，这时我们不需要加任何权重，因为第一个点的加入不需要任何边

        // 用t更新其他点到集合的距离
        for (int j = 0; j <= n; j++) dist[j] = min(dist[j], g[t][j]);

        st[t] = true;
    }

    return res;
}

int main()
{
    cin >> n >> m;

    // 初始化
    memset(g, 0x3f, sizeof g);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c); //无向图要同时更新邻接矩阵的两条边
    }

    int t = prim();

    if (t == INF) cout << "impossible" << endl;
    else cout << t << endl;

    return 0;
}