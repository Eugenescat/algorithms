#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int n, m;
vector<vector<char>> g;
vector<vector<int>> dist;
queue<PII> q;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void bfs() {
    while (q.size()) {
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= n || a < 0 || b >= m || b < 0) continue; // 越界
                if (dist[a][b] != -1) continue; // 已访问
                dist[a][b] = dist[x][y] + 1;
                q.push({a, b});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    // 这里要注意一下由于输入的是连续数字如'11011'，所以g保存的是char类型，否则会导致把11011当成一个数字
    g = vector<vector<char>>(n, vector<char>(m));
    dist = vector<vector<int>>(n, vector<int>(m, -1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '1') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    bfs();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}