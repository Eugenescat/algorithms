#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N]; // 邻接矩阵
int dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist); // 初始化每个点到第一个点的距离为最大值
    dist[1] = 0;                     // 1到1距离为0

    for (int i = 1; i <= n; i++) // 按顺序处理一遍每个点
    {
        int t = -1;
        // 在所有尚未确定最短路径的节点 j（即 st[j] == false）中找到距离最短的点。
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        // 使用当前确定的最短路径节点 t 来更新其邻接点的最短路径
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]); // 有可能tj之间没有边，这样就会加上无穷大，不影响结果

        st[t] = true; // t标记为确定最短路径
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    else
        return dist[n];
}

int main()
{
    cin >> n >> m;

    // 0x3f3f3f3f 是一种常用的大值初始化技巧，它的具体意义如下： 0x3f3f3f3f 是十进制的 1061109567，虽然它不是无穷大，但在很多场景中，这个值足够大，远远超过常见的边权重或计算结果，因此它可以用来代替无穷大。
    memset(g, 0x3f, sizeof g);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c); // 题目条件说可能会有重复边
    }

    int t = dijkstra();

    cout << t << endl;

    return 0;
}