/*
847. 图中点的层次

给定一个 n个点 m条边的有向图，图中可能存在重边和自环。

所有边的长度都是 1，点的编号为 1∼n
。

请你求出 1
 号点到 n
 号点的最短距离，如果从 1
 号点无法走到 n
 号点，输出 −1
。

输入格式
第一行包含两个整数 n
 和 m
。

接下来 m
 行，每行包含两个整数 a
 和 b
，表示存在一条从 a
 走到 b
 的长度为 1
 的边。

输出格式
输出一个整数，表示 1
 号点到 n
 号点的最短距离。

数据范围
1≤n,m≤105

输入样例：
4 5
1 2
2 3
3 4
1 3
1 4
输出样例：
1
*/


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m; // n 是节点的数量，m 是边的数量
int h[N], e[N], ne[N], idx;
int d[N], q[N]; // d[] 是节点到起点的最短距离数组，q[] 是队列，存放待处理的节点

void add(int a ,int b)
{
    e[idx] = b; ne[idx] = h[a], h[a] = idx;
    idx ++;
}

// 广度优先搜索（BFS）函数，返回从节点 1 到节点 n 的最短路径
int bfs()
{
    int hh = 0, tt = 0;  // hh 是队列头指针，tt 是队列尾指针
    q[0] = 1;            // 队列中首先放入起点 1

    memset(d, -1, sizeof d); // 初始化 d 数组，所有节点的距离初始值为 -1，表示未访问过
    d[1] = 0;            // 起点 1 到自己的距离为 0

    // 开始广度优先搜索
    while (hh <= tt)     // 当队列不为空时继续处理
    {
        int t = q[hh++]; // 从队列中取出当前处理的节点 t

        // 遍历从 t 出发的所有边
        for (int i = h[t]; i != -1; i = ne[i]) // i 是 t 的第一条边的索引，循环处理与 t 相连的所有边
        {
            int j = e[i];  // j 是 t 的邻接节点，表示通过边 i 到达的目标节点
            if (d[j] == -1) // 如果 j 节点还未被访问过（距离为 -1）
            {
                d[j] = d[t] + 1; // 更新节点 j 的距离，等于当前节点 t 的距离加 1
                q[++tt] = j;     // 将节点 j 加入队列的尾部，等待后续处理
            }
        }
    }

    return d[n];  // 返回节点 n 的最短距离（即从 1 到 n 的最短路径长度）
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
    }

    cout << bfs() << endl;

    return 0;
}