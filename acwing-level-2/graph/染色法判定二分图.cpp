#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 20;  // N 为最大节点数，M 为最大边数

int n, m;
int h[N], e[M], ne[M], idx;
int color[N]; // 颜色数组，color[i] 表示节点 i 的染色，1 或 2 表示两种不同的颜色

// 邻接表的 add 函数，用来将一条边 a -> b 插入图中
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++; // 将 b 节点加入到 a 的邻接表中，并更新边的索引 idx
}

// 把编号为 u 的点染成颜色 c
bool dfs(int u, int c)
{
    color[u] = c;  // 将当前节点 u 染成颜色 c

    // 遍历所有与 u 相邻的节点
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];  // j 是与 u 相邻的节点
        if (!color[j])  // 如果节点 j 还没有被染色
        {
            // 尝试将 j 染成与 u 不同的颜色（即 1 -> 2 或 2 -> 1）
            if (!dfs(j, 3 - c)) return false;  // 如果无法成功染色，返回 false
        }
        else if (color[j] == c) return false;  // 如果 j 已经被染色且颜色与 u 相同，则图不是二分图，返回 false
    }
    
    return true;  // 如果所有相邻节点都成功染色，返回 true
}

int main()
{
    cin >> n >> m;  // 输入节点数 n 和边数 m

    // 初始化邻接表，将所有 h 数组元素设为 -1，表示每个节点的邻接链表为空
    memset(h, -1, sizeof h);

    // 读取所有边的信息，并构建邻接表
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);  // 无向图需要同时添加 a -> b 和 b -> a 两条边
    }

    bool flag = true;  // 用来标记是否整个图是二分图
    // 遍历所有节点，防止图不连通的情况
    for (int i = 1; i <= n; i++)
        if (!color[i])  // 如果节点 i 没有被染色
        {
            // 从节点 i 开始 DFS 并尝试染色，初始颜色为 1
            if (!dfs(i, 1))
            {
                flag = false;  // 如果无法染色，标记为 false，并中断循环
                break;
            }
        }
        
    // 根据 flag 的值输出结果
    if (flag) cout << "Yes" << endl;  // 如果 flag 为 true，说明图是二分图
    else cout << "No" << endl;        // 如果 flag 为 false，说明图不是二分图

    return 0;
}
