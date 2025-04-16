#include <cstring>
#include <iostream>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n, m;
int f[N]; // 记录容量j下的最大价值
int g[N]; // 记录「这个最大价值是怎么得到的，有几种方法？」

int main()
{
    cin >> n >> m;

    memset(f, -0x3f, sizeof f);
    f[0] = 0; // 容量0时价值为0
    g[0] = 1; // 初始化，体积为0时方案数为1

    for (int i = 0; i < n; i ++ )
    {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j -- )
        {
            int maxv = max(f[j], f[j - v] + w);
            int cnt = 0;
            // 不选当前物品：如果原来的f[j]就已经是最大值，那就把它的组合数 g[j] 赋值给 s
            if (f[j] == maxv) cnt = g[j]; 
            // 不选当前物品：那就把 g[j - v] 加上来
            if (f[j - v] + w == maxv) cnt = (cnt + g[j - v]) % mod; 
            f[j] = maxv, g[j] = cnt;
        }
    }

    // 找出最大价值 f[i] 出现的位置（idx）
    int idx = 0;
    for (int i = 1; i <= m; i ++ )
        if (f[i] > f[idx])
            idx = i;

    // 统计有多少种方式能达到最大价值
    int sum = 0;
    for (int i = 0; i <= m; i ++ )
        if (f[i] == f[idx])
            sum = (sum + g[i]) % mod;

    cout << sum << endl;

    return 0;
}