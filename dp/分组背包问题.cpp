#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m; // 物品组数和背包容量
int v[N][N], w[N][N], s[N];
int f[N];

int main()
{
    cin >> n >> m;

    // 一共n组物品，填充每一组物品
    for (int i = 1; i <= n; i ++)
    {
        cin >> s[i]; // 该组物品数量
        // 处理组内每件物品
        for (int j = 0; j < s[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }

    // 很像01背包代码，但是多了一层组内k遍历，因为只能每组选1个
    for (int i = 1; i <= n; i++)        // 遍历每一组物品
        for (int j = m; j >= 0; j--)    // 逆序遍历背包容量
            for (int k = 0; k < s[i]; k++)  // 遍历该组内的所有物品
                if (v[i][k] <= j)
                    // f[j]：当前容量为j且不选当前组任意一个物品的情况下的最大价值
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    
    cout << f[m] << endl;

    return 0;
}