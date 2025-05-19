#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int n;
vector<vector<int>> g;
vector<vector<PII>> visit_from;

int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

void bfs(int nx, int ny) {
    queue<PII> q;
    q.push({nx, ny});
    
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= n || a < 0 || b >= n || b < 0) continue; // 越界
            if (g[a][b]) continue; // 不能走
            if (visit_from[a][b].first != -1) continue; // 已访问
            
            q.push({a, b});
            visit_from[a][b] = {x, y};
        }
    }
}

int main() {
    cin >> n;
    
    g = vector<vector<int>>(n, vector<int>(n));
    visit_from = vector<vector<PII>>(n, vector<PII>(n, {-1, -1}));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    
    bfs(n - 1, n - 1); // 因为需要输出一条从左上角到右下角的路线，而每一步只能存储上一步，所以倒序做bfs
    
    PII end = {0, 0};
    while (true) {
        cout << end.first << ' ' << end.second << endl;
        if (end.first == n - 1 && end.second == n - 1) break;
        end = visit_from[end.first][end.second];
    }
    
    return 0;
}