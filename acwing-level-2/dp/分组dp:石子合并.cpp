#include <iostream>
#include <algorithm>

using namespace std;

const int N = 310, INF = 1e9;

int n;
int s[N];
int f[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) s[i] += s[i-1]; // 前缀和

    for (int len = 2; len <= n; len ++) // len是区间长度，当 len = 2 时，我们处理所有长度为 2 的区间，然后逐步扩大到全长n
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int l = i, r = i + len - 1;
            f[l][r] = INF; // 初始化。不能在最开头进行初始化，因为会导致min结果永远是INF:min(INF, INF+INF+s[r]-s[l-1])
            for (int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l-1]);
        }

    cout << f[1][n] << endl;
    return 0;
}