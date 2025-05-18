#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int n, m;
vector<vector<char>> g;
vector<vector<bool>> visited;

void bfs(int a, int b) {
    queue<PII> q;
    q.push({a, b});
    
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = x-1; i <= x+1; i++) {
            for (int j = y-1; j <= y+1; j++) {
                if (i >= n || i < 0 || j >= m || j < 0) continue;
                if (i == x && j == y) continue;
                if (g[i][j] == '.' || visited[i][j]) continue;
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
}

int main () {
    cin >> n >> m;
    
    g = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'W' && !visited[i][j]) {
                bfs(i, j);
                cnt ++;
            }
        }
    }
    
    cout << cnt << endl;
    return 0;
}