/*
848. 有向图的拓扑序列

给定一个 n
 个点 m
 条边的有向图，点的编号是 1
 到 n
，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1
。

若一个由图中所有点构成的序列 A
 满足：对于图中的每条边 (x,y)
，x
 在 A
 中都出现在 y
 之前，则称 A
 是该图的一个拓扑序列。

输入格式
第一行包含两个整数 n
 和 m
。

接下来 m
 行，每行包含两个整数 x
 和 y
，表示存在一条从点 x
 到点 y
 的有向边 (x,y)
。

输出格式
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。

否则输出 −1
。

数据范围
1≤n,m≤105

输入样例：
3 3
1 2
2 3
1 3
输出样例：
1 2 3
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N], q[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx;
    idx ++;
}

bool topsort() // 拓扑排序函数，返回值表示是否可以进行拓扑排序（图是否为有向无环图）
{
    int hh = 0, tt = -1; // hh 和 tt 是队列的头部和尾部指针，用于存储拓扑排序中的节点

    // 初始化队列，找出所有入度为0的节点，作为拓扑排序的起点
    for (int i = 1; i <= n; i++) // 遍历所有节点
    {
        if (!d[i]) // 如果节点 i 的入度为 0，说明它没有依赖的前置节点
            q[++tt] = i; // 将该节点加入队列 q 中
    }

    // BFS（广度优先搜索）进行拓扑排序
    while (hh <= tt) // 当队列不为空时（hh <= tt），继续处理队列中的节点
    {
        int t = q[hh++]; // 取出队列中的第一个节点 t
        for (int i = h[t]; i != -1; i = ne[i]) // 遍历节点 t 的所有邻接节点
        {
            int j = e[i]; // 获取节点 t 指向的邻接节点 j
            d[j]--; // 将邻接节点 j 的入度减 1
            if (d[j] == 0) // 如果邻接节点 j 的入度减为 0，说明它可以加入拓扑序列
                q[++tt] = j; // 将节点 j 加入队列
        }
    }

    // 判断是否成功处理了所有节点，如果队列中的节点数量等于 n，则说明没有环
    // 因为 tt 是从 -1 开始的（即队列为空时，tt = -1），所以当我们处理完 n 个节点后，tt 应该等于 n - 1
    return tt == n - 1; // 如果 tt == n - 1，表示所有节点都被遍历了，图是无环的，可以拓扑排序；否则图中有环
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a,b);
        d[b] ++; // 保存a->b即b的入度++
    }

    if (topsort())
    {
        for (int i = 0; i < n; i++) // queue里的顺序恰好就是我们的拓扑排序
        {
            cout << q[i] << ' ' << endl;
        }
    }
    else{
        cout << "-1" << endl;
    }
    
    return 0;
}