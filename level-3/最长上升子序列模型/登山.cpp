#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N], g[N];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)  cin >> a[i];

    // 表示以i结尾的最长递增子序列
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1; // 自己本身1个
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }
    
    
    // 表示以i结尾的最长递增子序列
    for (int i = n; i >= 1; i--)
    {
        g[i] = 1; // 自己本身1个
        for (int j = n; j > i; j--)
            if (a[j] < a[i])
                g[i] = max(g[i], g[j] + 1);
    }
    
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, f[i] + g[i] - 1);
    }
    
    cout << res << endl;
    
    return 0;
}