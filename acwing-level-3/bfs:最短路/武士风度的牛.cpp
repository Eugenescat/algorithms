#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int n, m;
vector<vector<char>> g;
vector<vector<bool>> visited;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int nx, int ny) {
    queue<PII> q;
    q.push({nx, ny});
    int steps = 0;
    
    while (q.size()) {
        int sz = q.size();
        steps ++; // 对当前层的每个点往八个方向走一步
        while (sz--) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int i = 0; i < 8; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= m || a < 0 || b >= n || b < 0) continue; // 越界
                if (g[a][b] == 'H') return steps;
                if (g[a][b] == '*') continue; // 不能走
                if (visited[a][b]) continue; // 已访问
                
                q.push({a, b});
                visited[a][b] = true;
            }
        }
        
    }
    return 0;
}

int main() {
    cin >> n >> m;
    
    g = vector<vector<char>>(m, vector<char>(n));
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 'K') cout << bfs(i, j);
        }
    }
    
    return 0;
}