#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int w[N], f[N];

int main() {
    int k;
    cin >> k;
    
    while (k--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> w[i];
        
        // 正向求解
        int res = 0;
        // 表示以i结尾的最长递增子序列
        for (int i = 1; i <= n; i++) // 一轮循环得出当前f[i]最大值，循环结束前与res比较
        {
            f[i] = 1; // 自己本身1个
            for (int j = 1; j < i; j++)
                if (w[j] < w[i])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }
        
        // 表示以i结尾的最长递增子序列
        for (int i = n; i >= 1; i--) 
        {
            f[i] = 1; // 自己本身1个
            for (int j = n; j > i; j--)
                if (w[j] < w[i])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }
        
        cout << res << endl;
    }
    
    return 0;
    
}