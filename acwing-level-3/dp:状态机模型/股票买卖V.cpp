#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int n;
int w[N];
int f[N][3]; // 状态机模型: 0: 持仓，1: 卖出不持仓day1，2: 不持仓day2+

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

    f[0][0] = f[0][1] = -INF; // 第0天不可能处于0/1状态，f[0][0]、f[0][1]状态不合法
    f[0][2] = 0; // 第0天属于2状态，收益为0，初始化f[0][2] = 0
    for (int i = 1; i <= n; i ++ )
    {
        // 今天0：只能从0/2来
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w[i]);
        // 今天1：只能从0来
        f[i][1] = f[i - 1][0] + w[i];
        // 今天2：只能从1/2来
        f[i][2] = max(f[i - 1][2], f[i - 1][1]);
    }

    printf("%d\n", max(f[n][1], f[n][2])); // 最后一天，卖出不持仓day1，或者不持仓day2+的最大收益

    return 0;
}