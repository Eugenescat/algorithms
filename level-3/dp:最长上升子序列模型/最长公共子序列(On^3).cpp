#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3010;

int n;
int a[N], b[N];
int f[N][N]; // 以所有由a序列前i个字母、b序列前j个字母构成的，且以b[j]结尾的公共上升子序列的值

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i-1][j]; // 考虑a[i]不属于有效公共子序列的情况（f[i][j] 一定>= f[i-1][j]，所以可以先这样）
            if (a[i] == b[j]) { // 考虑a[i]属于有效公共子序列的情况(即a[i]==b[j]是序列最后一个值)
               f[i][j] = max(f[i][j], 1); // 空集，序列仅由(a[i]==b[j])一个值构成
                for (int k = 1; k < j; k++) {
                    if (b[k] < b[j]) f[i][j] = max(f[i][j], f[i][k] + 1);
                } 
            }
            
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, f[n][i]);
    
    cout << res << endl;
    return 0;
}