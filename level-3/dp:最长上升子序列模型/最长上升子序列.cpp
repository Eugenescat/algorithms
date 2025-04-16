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

    // 表示以i结尾的最长递增子序列
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1; // 自己本身1个
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }

    // 从f[1]到f[n]找出最大的
    int res = 1;
    for (int j = 1; j <= n; j++) res = max(res, f[j]);

    cout << res << endl;
}