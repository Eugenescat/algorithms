/*
这种对边数的限制常见于一些带有步骤或跳跃次数限制的问题，比如：
(1) 一个人从一个城市到另一个城市，最多可以停靠 k 次。
(2) 限制转机次数的最短路径问题。
*/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 1e4 + 10;

int n, m, k;
int dist[N], backup[N];

struct Edge
{
    int a, b, w;
} edges[M];

int bellman_ford()
{
    // 将所有节点的最短距离初始化为一个极大值，表示初始时所有节点都不可达
    memset(dist, 0x3f, sizeof dist); // 0x3f3f3f3f 是一个常见的技巧，表示无穷大（大约是10^9）
    // 起点 1 号节点到自己的距离初始化为 0，表示无需经过任何边即可到达自己
    dist[1] = 0;

    // Bellman-Ford 核心：进行 k 轮松弛操作，每轮迭代找到最多经过 i 条边的最短路径
    for (int i = 0; i < k; i ++ )
    {
        // 在每一轮松弛开始之前，将当前轮的最短距离复制到一个临时数组 last 中
        // 这样可以确保在当前轮松弛中，使用的是上一轮的最短距离来更新路径
        memcpy(backup, dist, sizeof dist);

        // 遍历所有边，对每条边进行松弛操作
        for (int j = 0; j < m; j ++ )
        {
            // 取出第 j 条边 e
            auto e = edges[j];

            // 松弛操作：检查是否可以通过边 e.a -> e.b 的路径使 e.b 的最短距离更短
            // 这里使用 backup[e.a] 是因为我们要基于没有受到本轮松弛操作影响的原来的结果来更新
            dist[e.b] = min(dist[e.b], backup[e.a] + e.w);
        }
    }
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < m; i ++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    bellman_ford();

    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible"); // 因为我们把初始化正无穷模拟存为0x3f3f3f3f，所以有可能存在负权边，将dist[n]从0x3f3f3f3f更新为10^9-w，但这条边实际上是无法到达的
    else printf("%d\n", dist[n]); 
}
