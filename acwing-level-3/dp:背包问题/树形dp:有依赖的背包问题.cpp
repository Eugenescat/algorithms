#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
int v[N], w[N];
int f[N][N];
vector<vector<int>> tree(N); // 用vector构建邻接表

// dfs(u): 计算以 u 为根的子树的背包方案
void dfs(int u)
{
    // 分组背包：合并当前节点的子树价值
    // 先遍历所有子节点（物品组）
    for (int son : tree[u]) {
        dfs(son); // 处理完后， f[son][j] 表示以 son 为根的子树，在容量 j 下的最优值
        // 现在需要把 son 的背包状态合并到 f[u]

        for (int j = m - v[u]; j >= 0; j--) { // 循环体积（预留出当前节点的体积v[u])
            for (int k = 0; k <= j; k++) { // 循环决策：给当前子节点预留多大体积（最大即除了给u的之外全给这个子节点）
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
            }
        }
    }
    // 以上填充了f[u][0 ~ m-v[u]]

    // 使用f[u][0 ~ m-v[u]]，更新了f[u][v[u] ~ m]
    for (int i = m; i >= v[u]; i--) f[u][i] = f[u][i - v[u]] + w[u];
    
    // 删除多余的f[u][0~v[u]]部分
    for (int i = 0; i < v[u]; i++) f[u][i] = 0;
}

int main()
{
    cin >> n >> m;
    int root = -1;

    for (int i = 1; i <= n; i++) {
        int p;  // p表示当前节点的根结点，用于建图
        cin >> v[i] >> w[i] >> p;
        if (p == -1) root = i;
        else tree[p].push_back(i); // 建图：p → i 是一条边
    }

    dfs(root);

    cout << f[root][m] << endl;

    return 0;
}
