#include <iostream>
#include <algorithm>

using namespace std;

// 定义最大物品数量 N 和背包容量 M
const int N = 25000, M = 2010;

// n 是初始的物品种类数量，m 是背包的最大容量
// v[N] 存储物品体积，w[N] 存储物品价值
// f[N] 是用于动态规划的数组，f[j] 表示容量为 j 的背包能取得的最大价值
int n, m;
int v[N], w[N];
int f[N];

int main()
{
    // 输入物品的种类数 n 和背包的最大容量 m
    cin >> n >> m;

    int cnt = 0; // cnt 计数实际分解后的物品数量

    // 对每一件物品进行二进制分解
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;

        // k 是每个单元指代的倍数，初始为 1，之后是2，4，8，16……
        int k = 1;
        while (k <= s)
        {
            cnt++;          // 保存一个单元
            v[cnt] = a * k; // 该单元物品体积为 a*k
            w[cnt] = b * k; // 该单元物品价值为 b*k
            s -= k;         // 减去已经处理的 k 件物品
            k *= 2;
        }
        // 处理剩下的。例如：18 = 1 + 2 + 4 + 8 + (剩下的3)。
        if (s > 0)
        {
            cnt++;          // 剩余的物品也算一组物品单元
            v[cnt] = a * s; // 剩余物品体积为 a*s
            w[cnt] = b * s; // 剩余物品价值为 b*s
        }
    }

    // 更新 n 为实际分解后的物品单元总数
    n = cnt;

    // 当作01背包问题求解
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;

    return 0;
}
