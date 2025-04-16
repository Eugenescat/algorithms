#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N][N]; // 从1~i中选，体积为j

int main()
{
    cin >> n;
    
    // 初始化：总体积为 0 的情况只有 1 种
    for (int i = 0; i <= n; i++) f[i][0] = 1;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i-1][j]; // 如果不选择当前物品。注意这里必须先进行状态转移，不能合并到下一行。因为f[i][j]的状态转移会影响下一轮迭代的计算
            if (j >= i) f[i][j] = (f[i][j] + f[i][j - i]) % mod;
            
        }
    
    cout << f[n][n] % mod << endl;

    return 0;
}