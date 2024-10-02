#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b) // 在h(a)插入节点b = 将a和b相连
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx;
    idx ++;
}

void dfs(int u)
{
    st[u] = true;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}

int main()
{
    memset(h, -1, sizeof h);
}