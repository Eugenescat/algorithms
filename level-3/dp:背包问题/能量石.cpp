#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;

int n;
struct Stone
{
    int s, e, l;
};

Stone stones[N];

bool cmp(Stone a, Stone b)
{
    return a.s * b.l < b.s * a.l;
}

int f[N][M];

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n;
        int m = 0; // 背包的容量（总时间）
        for (int i = 1; i <= n; i ++ )
        {
            int s, e, l;
            cin >> s >> e >> l;
            stones[i] = {s, e, l};
            m += s;
        }

        sort(stones + 1, stones + 1 + n, cmp);

        // 遍历每一个物品
        for (int i = 1; i <= n; i ++ )
        {   // 遍历背包容量（总时间）
            for (int j = 0; j <= m; j ++ )
            {
                f[i][j] = f[i - 1][j]; // 不论是否取当前物品，都要先传递“不选”的旧值，因为当j不够大时，下一行就直接不进入物品选择了
                if (j >= stones[i].s)
                {
                    int s = stones[i].s, e = stones[i].e, l = stones[i].l;
                    // 如果不取当前物品，价值就是 f[i - 1][j]
                    // 如果取当前物品，价值为 f[i - 1][j - s] + max(0, e - l * (j - s))
                    f[i][j] = max(f[i][j], f[i - 1][j - s] + max(0, e - l * (j - s)));
                }
            }
        }

        int res = 0;
        for (int i = 0; i <= m; i ++ ) res = max(res, f[n][i]); // 找出消耗不同时间得到的最大价值

        printf("Case #%d: %d\n", C, res);
    }

    return 0;
}