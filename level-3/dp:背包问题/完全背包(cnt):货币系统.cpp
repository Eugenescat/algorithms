#include <iostream>

using namespace std;

int const M = 3010;

long long f[M];

int main() {
    int n, m;
    cin >> n >> m;
    
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        for (int j = v; j <= m; j++) {
            f[j] += f[j - v];
        }   
    }
    
    cout << f[m] << endl;
    
    return 0;
}