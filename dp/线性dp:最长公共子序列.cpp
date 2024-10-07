#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main()
{
    cin >> n >> m;
    cin >> a + 1;
    cin >> b + 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
                {
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                    if(a[i] == b[j])
                        f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
                }
    
    // 因为f[i][j]表示的是所有由前i个和前j个字母构成的子序列集合，而非必须以i/j结尾的子序列，所以可以直接用f[n][m]
    cout << f[n][m] << endl;
}