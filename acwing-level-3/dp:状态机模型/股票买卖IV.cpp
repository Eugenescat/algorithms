#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010, M = 110, INF = 0x3f3f3f3f;

int n, m;
int w[N]; // 只有一支股票，每天的价格
int f[N][M][2]; // 前 i 天，已经做了 j 次交易（完整买+卖），当前持仓状态为 k 时的最大收益

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

    memset(f, -0x3f, sizeof f); // 初始化为负无穷（表示不合法状态）
    for (int i = 0; i <= n; i ++ ) f[i][0][0] = 0; // 没做交易j=0，也没持仓k=0时，收益为0

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            // 如果今天是不持仓状态
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]); // 昨天也不持仓，或者昨天是持仓状态，今天卖出
            // 如果今天持仓
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]); // 昨天也持仓，或者昨天是非持仓状态，今天买入
        }

    int res = 0;
    // 最后一天n，做了任意次数交易后，处于不持仓状态0的最大收益
    for (int i = 0; i <= m; i ++ ) res = max(res, f[n][i][0]); 

    printf("%d\n", res);

    return 0;
}