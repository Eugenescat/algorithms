#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int w[N], f[N][2];

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

        for (int i = 1; i <= n; i ++ )
        {
            // 如果不抢第i个
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            // 如果抢第i个
            f[i][1] = f[i - 1][0] + w[i];
        }

        printf("%d\n", max(f[n][0], f[n][1]));
    }

    return 0;
}