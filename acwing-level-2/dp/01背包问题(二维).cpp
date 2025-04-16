#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m; // 物品个数，背包容量
int v[N], w[N];
int f[N][N]; // 全局变量默认是0

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++) // i=0时w为0，符合初始状态
        for (int j= 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j]; // 将左侧状态传递过来
            if (j >= v[i]) // 如果还有空间放v[i]
                f[i][j] = max(f[i][j], f[i-1][j-v[i]] + w[i]);
        }

    cout << f[n][m] << endl;

    return 0;
}