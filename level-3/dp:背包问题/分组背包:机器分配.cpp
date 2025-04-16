#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11, M = 16;

int n, m;
int w[N][M];
int f[N][M];
int way[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> w[i][j];

    // 把分公司数量当作物品数量
    for (int i = 1; i <= n; i ++ )
        // 在这道题，我们把用掉的机器数量当作体积，遍历[1, m]个机器数量
        for (int j = 0; j <= m; j ++ )
            for (int k = 0; k <= j; k ++ )
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);

    cout << f[n][m] << endl;

    int j = m;
    // 遍历n个节点（n个公司）
    for (int i = n; i; i -- )
        // 找到当前节点是哪个（用了几台机器）
        for (int k = 0; k <= j; k ++ )
            if (f[i][j] == f[i - 1][j - k] + w[i][k])
            {
                way[i] = k;
                j -= k;
                break;
            }

    for (int i = 1; i <= n; i ++ ) cout << i << ' ' << way[i] << endl;

    return 0;
}
