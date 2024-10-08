#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;

int n, m;
char a[N], b[N];
int f[N][N];

int main()
{
    cin >> n >> a + 1;
    cin >> m >> b + 1;

    // 从0个字符变成b[0～j]需要j步增加
    for (int i = 0; i <= m; i++) f[0][i] = i;
    // 从a[0~i]变成0个字符需要i步删除
    for (int i = 0; i <= n; i++) f[i][0] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1);
            if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i-1][j-1]);
            else f[i][j] = min(f[i][j], f[i-1][j-1] + 1);
        }
    
    // 打印把a的n个字符变成b的前m个字符
    cout << f[n][m] << endl;

    return 0;
}