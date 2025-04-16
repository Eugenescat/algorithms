#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25010;

int n;
int a[N];
bool f[N]; // 维护截至目前的ai对哪些数字能凑出，哪些数字凑不出

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        sort(a, a + n);
    
        // a[]存在的最大值
        int m = a[n - 1];
        memset(f, 0, sizeof f);
        f[0] = true; // 初始化0是自动可以凑成的

        int k = 0;
        for (int i = 0; i < n; i ++ )
        {
            // 如果之前的a1～ai-1不能凑出ai，则当前ai有效
            if (!f[a[i]]) k ++ ;
            // 用当前ai更新一遍剩下的值
            for (int j = a[i]; j <= m; j ++ )
                f[j] |= f[j - a[i]];
        }

        cout << k << endl;
    }

    return 0;
}