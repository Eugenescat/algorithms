#include <iostream>
#include <algorithm>

int const N = 1010;

int n = 4;
int m;
int v[4] = {10, 20, 50, 100};
int f[N];

using namespace std;

int main() {
    cin >> m;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= m; j++) { // 正序 从小到大
            f[j] += f[j - v[i]]; // 计数问题（如方案数统计），叠加了本轮循环中的所有可能（代表可重复使用）
        }
    }
    
    cout << f[m] << endl;
    return 0;
}