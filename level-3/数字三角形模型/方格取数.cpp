#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;

int w[N][N];
int f[2*N][N][N];

int main() {
    int n;
    cin >> n;

    int i, j, val;
    while (cin >> i >> j >> val, i || j || val) w[i][j] = val;

    for (int k = 2; k <= n + n; k++) {
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >=1 && j2 <= n) {
                    int overlap_or_not_sum = w[i1][j1];
                    if (i1 != i2) overlap_or_not_sum += w[i2][j2]; // 如果重复走了，就不能重复取
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2-1] + overlap_or_not_sum);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2] + overlap_or_not_sum);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2-1] + overlap_or_not_sum);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2] + overlap_or_not_sum);
                }
            }
        }
    }

    cout << f[n+n][n][n];
}