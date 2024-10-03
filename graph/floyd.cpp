#include <iostream>

using namespace std;

const int N = 210, INF = 1e9; // 伪造一个正无穷

int n, m, k;
int g[N][N]; // 初始时只是邻接矩阵，但通过Floyd算法逐渐更新为通过其他节点的可能更短的路径。

// 动态规划的核心思想：
// Floyd-Warshall 算法引入一个中间节点 k，然后检查从 i 到 j 之间是否可以通过 k 使路径更短。
// 如果 g[i][k] + g[k][j] < g[i][j]，说明通过中间节点 k，可以找到一条从 i 到 j 的更短路径，于是更新 g[i][j] 为这个新的更短路径长度。
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
    cin >> n >> m >> k;

    // 将邻接矩阵初始化为无穷大
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;

    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        g[a][b] = min(g[a][b], w); // 处理可能存在的重边
    }

    floyd();

    while (k--)
    {
        int a,b;
        cin >> a >> b;
        
        if (g[a][b] > INF /2) cout << "impossible" << endl;
        else cout << g[a][b] << endl;
    }

    return 0;
}