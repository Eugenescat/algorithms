#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n, m, q;
int a[N][N], s[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    
    for (int i = 1; i <= n; i ++) // 为什么不是从0开始，而是从1到n？因为第一个格子就是从1开始。默认a[0][0]=0
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[i][j]);
    
    // 默认s[0][k]和s[k][0]都是0
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]; // 初始化二维前缀和
    
    while (q--)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]); // 算子矩阵的和
    }
    
    return 0;
}