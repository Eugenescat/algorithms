#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m; // 物品个数，背包容量
int v[N], w[N];
int f[N]; // 全局变量默认是0

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++) // i=0时w为0，符合初始状态
        for (int j= m; j >= v[i]; j--) // 为什么要反向遍历：如果正序遍历，f[j-v[i]]会先于f[j]被计算，即此时用到的f[j-v[i]]实际上是f[i][j-v[i]]，而不是我们希望的f[i-1][j-v[i]]
            // f[j]: 当前容量为j且不选当前物品的情况下的最大价值
            f[j] = max(f[j], f[j-v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}