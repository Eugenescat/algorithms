#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20010;

int m, n;
int v[N];
int f[N]; // 最大空间为j的情况下可以使用前i个物品能占用的最大空间

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
       cin >> v[i]; 
       
       for (int j = m; j >= v[i]; j--) {
           f[j] = max(f[j], f[j - v[i]] + v[i]);
       }
    }
    
    cout << m - f[m] << endl;
    
    return 0;
}