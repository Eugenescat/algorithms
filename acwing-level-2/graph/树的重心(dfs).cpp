#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
bool st[N];

int ans = N;

void add(int a, int b) // 在h(a)插入节点b = 将a和b相连
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx;
    idx ++;
}

int dfs(int u)
{
    st[u] = true; // 标记一下，已经被搜索过了

    int sum = 1, res = 0; // 每次剩余联通块中点数的最大值
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum); // n是总节点数，减去

    ans = min(ans, res);
    return sum;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 0; i < n-1; i++) 
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b,a);
    }
    dfs(1);

    cout << ans << endl;

    return 0;
}