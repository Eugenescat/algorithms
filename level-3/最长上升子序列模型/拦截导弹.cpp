#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N], g[N];

int main()
{
    while (cin >> a[n]) n++;

    int res = 0;
    // 表示以i结尾的最长递增子序列
    for (int i = 0; i < n; i++)
    {
        f[i] = 1; // 自己本身1个
        for (int j = 0; j < i; j++)
            if (a[j] >= a[i])
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }

    cout << res << endl;
    
    int cnt = 0; // g[N]中的子序列数量
    for (int i = 0; i < n; i++) {
        int k = 0; // a[i]应该放入g[N]的某个下标k
        while (k < cnt && g[k] < a[i]) k++; // 找到第一个大于等于当前数的子序列结尾
        g[k] = a[i]; // 更新当前序列/或新开一个序列，放入q[i]
        if (k >= cnt) cnt ++;
    }
    
    cout << cnt << endl;
}