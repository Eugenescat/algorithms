#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int a[N], s[N];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]); // 注意这里是i<=n，因为是从1到n。
    
    s[0] = 0;
    for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i]; // 前缀和系统初始化。
    
    while (m --)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]); // 前缀和公式
    }
}