#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 5010;

int n;
PII q[N];
int f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> q[i].first >> q[i].second;
    sort(q, q + n + 1); // 因为习惯性用了从1开始
    
    int res = 0;
    // 表示以i结尾的最长递增子序列
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1; // 自己本身1个
        for (int j = 1; j < i; j++)
            if (q[j].second < q[i].second)
                f[i] = max(f[i], f[j] + 1); 
        res = max(res, f[i]);
    }
    
    cout << res << endl;
    
    return 0;
}