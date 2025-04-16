#include <iostream>
#include <algorithm>

int const N = 10010;

int n, m;
int v;
int f[N];

using namespace std;

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> v;
        f[0] = 1;
        for (int j = m; j >= v; j--) {
            f[j] = f[j] + f[j-v];
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}