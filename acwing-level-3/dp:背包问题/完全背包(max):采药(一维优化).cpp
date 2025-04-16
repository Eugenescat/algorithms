#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int m, n;
int t[N], v[N];
int f[N];

int main() {
    cin >> m >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> v[i];
        
        for (int j = m; j >= 1; j--) { // 倒序 从大到小
            if (j >= t[i]) f[j] = max(f[j], f[j - t[i]] + v[i]); // 求最值问题（如最大价值），避免状态被重复使用（防止一轮内叠加）
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}