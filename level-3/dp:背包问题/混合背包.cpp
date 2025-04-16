#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int f[N];

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i ++ )
    {
        int v, w, s;
        cin >> v >> w >> s;
        if (!s) // 完全背包
        {
            // 用当前物品{v,w}更新所有可行的f[j]（由于j从小到大，所以自动覆盖考虑了最大可能的k*v）
            for (int j = v; j <= m; j ++ )
                f[j] = max(f[j], f[j - v] + w);
        }
        else
        {
            if (s == -1) s = 1; // 01背包相当于每个物品只能取一次的多重背包
            // 二进制优化
            // 当前物品最多取s件，所以将s拆分成k=1,2,4,8...,每个k当成一件新的物品，构造出一组01背包
            for (int k = 1; k <= s; k *= 2)
            {
                for (int j = m; j >= k * v; j -- )
                    f[j] = max(f[j], f[j - k * v] + k * w);
                s -= k;
            }
            if (s) // 剩下s-k件物品打成一个包
            {
                for (int j = m; j >= s * v; j -- )
                    f[j] = max(f[j], f[j - s * v] + s * w);
            }
        }
    }

    cout << f[m] << endl;

    return 0;
}