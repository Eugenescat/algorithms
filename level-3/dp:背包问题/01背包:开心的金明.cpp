#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 30010;

int m, n;
int v[N], p[N];
int f[N];

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
       cin >> v[i] >> p[i]; 
       
       for (int j = m; j >= v[i]; j--) {
           f[j] = max(f[j], f[j - v[i]] + v[i] * p[i]);
       }
    }
    
    cout << f[m] << endl;
    
    return 0;
}