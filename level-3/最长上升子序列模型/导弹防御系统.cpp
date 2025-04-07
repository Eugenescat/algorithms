#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int ans;
int a[N];
int up[N], down[N];

void dfs(int u, int su, int sd) {
    if (su + sd >= ans) return;  // ans是之前保存的结果，如果当前su+sd已经不可能更优了，就停止dfs
    if (u == n) {
        ans = su + sd;
        return;
    }
    
    // 放到上升子序列
    int k = 0; // a[i]应该放入up[N]的某个下标k
    while (k < su && up[k] >= a[u]) k++; // 找到第一个小于当前数的子序列结尾
    int temp = up[k];
    up[k] = a[u]; // 更新当前序列/或新开一个序列，放入q[i]
    if (k >= su) dfs(u+1, su+1, sd);
    else dfs(u+1, su, sd);
    up[k] = temp; // 恢复路径
    
    // 放到下降子序列
    k = 0; // a[i]应该放入up[N]的某个下标k
    while (k < sd && down[k] <= a[u]) k++; // 找到第一个大于当前数的子序列结尾
    temp = down[k];
    down[k] = a[u]; // 更新当前序列/或新开一个序列，放入q[i]
    if (k >= sd) dfs(u+1, su, sd+1);
    else dfs(u+1, su, sd);
    down[k] = temp; // 恢复路径
}

int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++) cin >> a[i];
        
        ans = n; // 这一步也算剪枝，最差的情况是每个导弹单独作为一个序列
        dfs(0, 0, 0);
        
        cout << ans << endl;
    }
}