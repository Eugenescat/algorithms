#include <iostream>
#include <algorithm>

using namespace std;

int const N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    
    for (int i = 1; i <= n; i++) {
        
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i-1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i-1][j - v[i]] + w[i]);
        }
    }
    
    // f[n][m]是质量最大值，从质量最大值方案倒回，找到对应的物品
    int j = m;
    for (int i = n; i >= 1; i--) {
        if (j >= v[i] && f[i][j] == f[i - 1][j - v[i]] + w[i]) { // 如果构造f[n][m]时是选了当前物品
            cout << i << ' ';
            j -= v[i]; // 减去当前用掉的体积
        }
    }
    
    return 0;
}