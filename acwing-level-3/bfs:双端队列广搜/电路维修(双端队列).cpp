#include <iostream>
#include <deque>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int INF = 1e5;

int n, m;
vector<vector<char>> g; // 表示所有输入的电路
vector<vector<int>> dist; // 表示所有点

int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1}; // 点{x, y}四周的点{a, b}坐标
int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1}; // 对应的格子坐标

void bfs() {
    deque<PII> q;
    q.push_back({0, 0});
    dist[0][0] = 0;
    
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            int u = x + ix[i], v = y + iy[i];
            if (a > n || a < 0 || b > m || b < 0) continue;
            if (u >= n || u < 0 || v >= m || v < 0) continue;
            
            int cost;
            if (i == 0 && g[u][v] == '/' || 
                i == 1 && g[u][v] == '\\' ||
                i == 2 && g[u][v] == '/' ||
                i == 3 && g[u][v] == '\\') {
                cost = 1;
            } else {
                cost = 0;
            }
            
            if (dist[a][b] > dist[x][y] + cost) {
                dist[a][b] = dist[x][y] + cost;
                // 如果边权为0，优先放到队列前面，如果边权为1，放到队列后面
                if (cost == 0) q.push_front({a, b});
                else q.push_back({a, b});
            } // 如果dist[a][b]未更新，就不用再放入队列
        }
    }
    
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        g = vector<vector<char>>(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }
        dist = vector<vector<int>>(n+1, vector<int>(m+1, INF));
        
        bfs();
        
        if (dist[n][m] == INF) cout << "NO SOLUTION";
        else cout << dist[n][m];
        cout << endl;
    }
    
}