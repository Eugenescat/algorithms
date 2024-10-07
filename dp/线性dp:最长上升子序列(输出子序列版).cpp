#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N], g[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 表示以i结尾的最长递增子序列
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1; // 自己本身1个
        g[i] = 0;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                if (f[i] < f[j] + 1)
                    {
                        f[i] = f[j] + 1;
                        g[i] = j; // 记录上一个状态的位置
                    }
    }

    // 从f[1]到f[n]找出最大的，记录最大的下标
    int k = 0;
    for (int j = 1; j <= n; j++)
            if (f[k] < f[j])
                k = j;

    int len = f[k];
    cout << len << endl;

    // 倒序排列打印
    for (int i = 0; i < len; i++)
    {
        cout << a[k];
        k = g[k];
    }

    return 0;
}