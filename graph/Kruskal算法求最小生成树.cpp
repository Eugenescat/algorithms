#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n, m; // n 表示图中的节点数，m 表示图中的边数
int p[N]; // 用于并查集，p[i] 表示节点 i 所在集合的根节点

// 边的结构体，表示一条边由节点 a 和 b 组成，权重为 w
struct Edge
{
    int a, b, w;

    // 重载小于运算符，用于在 Kruskal 算法中对边按权重升序排序
    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
} edges[N]; // edges 数组，用来存储所有边

// 并查集的 find 函数，查找节点 x 所在集合的根节点，并执行路径压缩优化
int find(int x)
{
    // 如果节点 x 不是它自己的父节点，递归找到根节点，并进行路径压缩
    if(p[x] != x) p[x] = find(p[x]);
    return p[x]; // 返回节点 x 所在集合的根节点
}

int main()
{
    cin >> n >> m; // 输入节点数 n 和边数 m

    // 依次构建 m 条边
    for (int i = 0; i < m; i++)
    {
        int a, b, w; // 边的两个端点 a 和 b，以及边的权重 w
        cin >> a >> b >> w; // 输入每条边的信息
        edges[i] = {a, b, w}; // 将这条边存入 edges 数组中
    }

    // 第一步：把所有的边按照权重从小到大排序
    // Kruskal 算法要求首先对所有边进行升序排序
    sort(edges, edges + m);

    // 初始化并查集，每个节点的父节点初始化为它自己
    for (int i = 1; i <= n; i++) p[i] = i;

    // 从小到大枚举所有边，尝试构造最小生成树
    int res = 0, cnt = 0; // res 用来存储最小生成树的总权重，cnt 记录已加入树中的边数
    for (int i = 0; i < m; i ++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w; // 取出第 i 条边的起点 a，终点 b 和权重 w

        // 使用并查集的 find 操作查找 a 和 b 的根节点
        a = find(a), b = find(b);
        
        // 如果 a 和 b 不在同一个集合中，说明这条边可以加入最小生成树
        if (a != b)
        {
            p[a] = b; // 将 a 和 b 合并，标志着它们被加入了同一个集合
            res += w; // 将这条边的权重加入结果中
            cnt ++;   // 已加入最小生成树的边数加 1
        }
    }

    // 最后检查最小生成树是否包含了 n - 1 条边（因为最小生成树包含 n 个节点和 n - 1 条边）
    if (cnt < n - 1) cout << "impossible" << endl; // 如果边数不够，说明图不连通，无法构造最小生成树
    else cout << res << endl; // 否则输出最小生成树的总权重

    return 0;
}
