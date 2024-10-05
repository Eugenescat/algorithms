/*
在二分图最大匹配问题中，匹配数指的是在一个二分图中，可以配对的边数的最大数量，且每个顶点只能参与一次匹配。
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 1e5 + 10;  // 定义常量，N 表示左侧的最大顶点数，M 表示最多的边数

int n1, n2, m; // n1 是左侧的顶点数，n2 是右侧的顶点数，m 是边数
int h[N], e[M], ne[M], idx; // 邻接表：h 存储每个顶点的边，e 存储某条边的终点，ne 存储下一条边的索引，idx 表示边的数量
int match[N]; // 存储右侧顶点的匹配状态，match[j] 表示右侧顶点 j 匹配到的左侧顶点
bool st[N]; // 访问标记数组，st[j] 表示右侧顶点 j 是否在本次查找中被访问过

// 邻接表的 add 函数，添加一条从左侧顶点 a 到右侧顶点 b 的边
void add(int a, int b)
{
    e[idx] = b;       // 边的终点是 b
    ne[idx] = h[a];   // 将 a 的邻接表的旧值记录到 ne[idx] 中
    h[a] = idx++;     // 更新 a 的邻接表为当前边，并将 idx 加 1
}

// 匈牙利算法的核心：寻找是否可以找到从左侧顶点 x 的增广路径
bool find(int x)
{
    // 遍历 x 顶点的所有邻接边
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])    // 如果右侧顶点 j 在当前增广路径中还没有被访问过(没有被连过)
        {
            st[j] = true; // 标记顶点 j 已被访问

            // 如果 j 没有被匹配（match[j] == 0），我们可以直接匹配 x 和 j，并记录 match[j] = x
            // 如果 j 已经被匹配了（match[j] != 0），那么我们尝试递归地为当前匹配 j 的左侧顶点 match[j] 找到另一个匹配，从而让 j 重新匹配 x
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x; // 匈牙利算法的核心是确保右侧顶点 j 不被多次匹配，因此记录match[j]
                return true;  // 找到增广路径，返回 true
            }
        }
    }
    return false;  // 如果找不到增广路径，返回 false
}

int main()
{
    // 读取左侧顶点数 n1，右侧顶点数 n2 和边数 m
    cin >> n1 >> n2 >> m;

    // 初始化邻接表，将所有顶点的邻接表头 h 初始化为 -1，表示没有邻接边
    memset(h, -1, sizeof h);

    // 读取 m 条边，并将边信息存入邻接表
    while (m--)
    {
        int a, b;
        cin >> a >> b; // 读取一条边，从左侧顶点 a 到右侧顶点 b
        add(a, b);     // 将该边添加到邻接表中
    }

    int res = 0; // 用于存储最大匹配数
    // 遍历左侧每个顶点，尝试为每个顶点找到增广路径
    for (int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof st); // 每次尝试匹配时，重置访问标记数组
        if (find(i)) res++; // 如果找到增广路径，匹配数加 1
    }

    // 输出最大匹配数
    cout << res << endl;

    return 0;
}
