#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int n, m;
vector<vector<int>> g;
vector<vector<bool>> visited;

// 这里debug了很久，因为搞错了在编程里x轴和y轴跟数学里是反过来的
// 这里的x是向下的纵轴，y是向右的横轴，表示西北东南
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

int bfs(int nx, int ny) {
    queue<PII> q;
    q.push({nx, ny});
    visited[nx][ny] = true;
    
    int area = 0;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        area ++;
        
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= n || a < 0 || b >= m || b < 0) continue; // 越界
            if (visited[a][b]) continue; // 已访问
            if (g[x][y] & (1 << i)) continue; // 有墙
            
            q.push({a, b});
            visited[a][b] = true;
        }
    }

    return area;
}

int main () {
    cin >> n >> m;
    
    g = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    
    int cnt = 0, max_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                max_area = max(max_area, bfs(i, j));
                cnt ++;
            }
        }
    }
    
    cout << cnt << endl;
    cout << max_area << endl;

    return 0;
}