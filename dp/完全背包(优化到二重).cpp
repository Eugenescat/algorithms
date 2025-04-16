#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            f[i][j] = f[i-1][j]; // 不选当前物品
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j-v[i]] + w[i]); // 优化：直接套用之前[j-v[i]]这个更新过的体积
        }
    }

    cout << f[n][m] << endl;

    return 0;
}