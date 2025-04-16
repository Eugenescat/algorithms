#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int m, n;
int t[N], v[N];
int f[N][N];

int main() {
    cin >> m >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> v[i];
        
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i-1][j];
            if (j >= t[i]) f[i][j] = max(f[i][j], f[i-1][j - t[i]] + v[i]);
        }
    }
    
    cout << f[n][m] << endl;
    
    return 0;
}