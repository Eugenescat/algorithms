#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 6e3 + 10;

int n;
int happy[N];
int h[N], e[N], ne[N], idx;
int f[N][2];
bool has_parent[N];

void add(int a, int b)
{
    e[idx] = b; ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{
    f[u][1] = happy[u];
    // 遍历u的子节点
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i]; // 注意j才是对应的值(也就是职员编号)
        dfs(j);

        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> happy[i];

    memset(h, -1, sizeof h);
    // 存储树形关系，记录每个职员是否有parent节点
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        has_parent[a] = true;
        add(b, a);
    }

    // 遍历1～n个职员，找到职级最高的根节点
    int root = 1;
    while (has_parent[root]) root ++;

    dfs(root);

    cout << max(f[root][1], f[root][0]);

    return 0;
}