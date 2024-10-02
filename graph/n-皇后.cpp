#include <iostream>

using namespace std;

const int N = 10;

int n;
char g[N][N]; 
bool col[N], dg[N], ndg[N];

void dfs(int u) // u是当前位置
{
    if (u == n)
    {
        for (int i = 0; i < n; i++) cout << g[i] << endl;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dg[u + i] && !ndg[u - i + n])
        {
            g[u][i] = 'Q';
            col[i] = dg[u+i] = ndg[n - u + i] = true;
            dfs(u + 1);
            g[u][i] = '.';
            col[i] = dg[u+i] = ndg[n - u + i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
            
    dfs(0);
    
    return 0;
}