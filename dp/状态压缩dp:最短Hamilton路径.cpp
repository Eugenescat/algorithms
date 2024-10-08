#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20, M = 1 << N; // N 表示城市的最大数量，M 是用来表示所有城市状态的掩码

int n; // 城市数量
int w[N][N]; // 邻接矩阵 w，用于存储城市间的距离
int f[M][N]; // f[S][j] 表示从起点出发，访问状态 S 中的城市，最后一个停在城市 j 的最短路径长度

int main()
{
    cin >> n; // 读取城市数量
    // 读取每两个城市之间的距离
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j]; // 城市 i 到城市 j 的距离

    memset(f, 0x3f, sizeof f); // 将数组 f 初始化为一个很大的值（0x3f3f3f3f），表示无穷大
    f[1][0] = 0; // 初始状态，从城市 0 出发，只访问城市 0，自然距离为 0

    // 遍历所有状态，i 表示城市的集合（用位表示哪些城市被访问过）
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            // 如果状态 i 中包含城市 j
            if (i >> j & 1)
                // 尝试从状态 i 中的每个城市 k 转移到城市 j
                for (int k = 0; k < n; k++)
                    // 如果状态 i 中也包含城市 k
                    if (i >> k & 1)
                        // 更新 f[i][j]，从状态 i 移动到城市 j 的最短路径
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);

    cout << f[(1 << n) - 1][n - 1]; // 输出访问完所有城市并回到起点的最短路径长度

    return 0;
}
