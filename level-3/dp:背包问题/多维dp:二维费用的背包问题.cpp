#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int n, vmax, mmax;
int f[N][N];

int main() {
    cin >> n >> vmax >> mmax;
    
    for (int i = 1; i <= n; i++) {
        int v, m, w;
        cin >> v >> m >> w;
        
        for (int j = vmax; j >= v; j--) {
            for (int k = mmax; k >= m; k--) {
                f[j][k] = max(f[j][k], f[j-v][k-m] + w);
            }
        }
    }
    
    cout << f[vmax][mmax] << endl;
    
    return 0;
}