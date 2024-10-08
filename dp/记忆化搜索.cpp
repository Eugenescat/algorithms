#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;

int n, m;
int h[N][N]; // 输入图
int f[N][N]; // 所有从[i,j]开始滑的路径最大长度

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dp(int x, int y)
{
    int &v = f[x][y];
    if (v != -1) return v; // 已经滑到过

    v = 1; // 从f[x][y]开始滑的路径初始长度为1（区域本身）

    // 枚举四个方向
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && h[a][b] < h[x][y])
            v = max(v, dp(a, b) + 1);
    }

    return v;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[i][j];

    memset(f, -1, sizeof f);

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, dp(i, j));
    
    cout << res << endl;

    return 0;
}