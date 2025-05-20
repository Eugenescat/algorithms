/* 这样做会超时 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int INF = 1e5;

int n, m;
vector<vector<char>> g;   // 表示所有输入的电路
vector<vector<int>> dist; // 表示所有点

int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1}; // 对应的格子坐标

void bfs()
{
    queue<PII> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            int u = x + ix[i], v = y + iy[i];
            if (a > n || a < 0 || b > m || b < 0) continue;
            if (u >= n || u < 0 || v >= m || v < 0) continue;
            int backup = dist[a][b];
            if (i == 0 && g[u][v] == '/' || 
                i == 1 && g[u][v] == '\\' ||
                i == 2 && g[u][v] == '/' ||
                i == 3 && g[u][v] == '\\')
            {
                dist[a][b] = min(dist[a][b], dist[x][y] + 1);
            }
            else
            {
                dist[a][b] = min(dist[a][b], dist[x][y]);
            }

            if (backup != dist[a][b])
                q.push({a, b});
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        g = vector<vector<char>>(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> g[i][j];
            }
        }
        dist = vector<vector<int>>(n + 1, vector<int>(m + 1, INF));

        bfs();

        if (dist[n][m] == INF)
            cout << "NO SOLUTION";
        else
            cout << dist[n][m];
        cout << endl;
    }
}