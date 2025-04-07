#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 表示以i结尾的最大递增子序列
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = a[i]; // 自己本身
        for (int j = 1; j < i; j++)
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + a[i]);
            }
        res = max(res, f[i]);
    }

    cout << res << endl;
}