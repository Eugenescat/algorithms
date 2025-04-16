#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 22, M = 80;

int n, m, k;
int f[N][M]; // 表示所有从前i个物品中选，满足氧气【至少j】且氮气【至少k】，的选法中最小气缸重量

int main()
{
    cin >> n >> m >> k;
    
    memset(f, 0x3f, sizeof f); // 全部填充为INF
    f[0][0] = 0; // 除了00初始化为0（因为什么都不选，气缸重量为0）

    while (k -- )
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        
        for (int j = n; j >= 0; j--) {  // 采用的是上一轮物品，所以j\k都要倒序遍历
            for (int k = m; k >= 0; k--) {
                // 因为表示的是【至少】，所以不需要判断j > v1, k > v2
                // 如果不满足i >= v1 && j >= v2，就自动退回到f[0][0]的状态的基础上只使用1个当前气缸
                f[j][k] = min(f[j][k], f[max(0, j - v1)][max(0, k - v2)] + w);
            }
        }
    }
    
    cout << f[n][m] << endl;
    
    return 0;
}