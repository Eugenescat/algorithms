#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int n;
vector<vector<int>> g;
vector<vector<bool>> visited;

void bfs(int nx, int ny, bool& has_higher, bool& has_lower) {
    queue<PII> q;
    q.push({nx, ny});
    visited[nx][ny] = true;
    
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = x-1; i <= x+1; i++) {
            for (int j = y-1; j <= y+1; j++) {
                if (i >= n || i < 0 || j >= n || j < 0) continue; // 越界
            
                if (g[i][j] > g[x][y]) has_higher = true;
                if (g[i][j] < g[x][y]) has_lower = true;
                if (g[i][j] == g[x][y] && !visited[i][j]) {
                    visited[i][j] = true;
                    q.push({i, j});
                }  
            }
        }
    }
}

int main () {
    cin >> n;
    
    g = vector<vector<int>>(n, vector<int>(n));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    
    int peak = 0, valley = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bool has_higher = false, has_lower = false;
                bfs(i, j, has_higher, has_lower);
                if (!has_higher) peak++;
                if (!has_lower) valley++;
            }
        }
    }
    
    cout << peak << ' ' << valley << endl;

    return 0;
}