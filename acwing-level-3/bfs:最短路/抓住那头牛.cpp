#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int n, k;
vector<bool> visited;

int bfs(int nx) {
    queue<int> q;
    q.push(nx);
    visited[nx] = true;
    int steps = 0;
    
    while (q.size()) {
        int sz = q.size();
        while (sz--) {
            int x = q.front();
            q.pop();
            if (x == k) return steps; // 先不走，判断取出来的点是否已经是终点
            
            if (x - 1 >= 0 && !visited[x - 1]) {
                visited[x-1] = true;
                q.push(x-1);
            }
            if (x + 1 <= N && !visited[x + 1]) {
                visited[x+1] = true;
                q.push(x+1);
            }
            if (2 * x <= N && !visited[2 * x]) {
                visited[2 * x] = true;
                q.push(2 * x);
            }
        }
        steps ++;
    }
    
    return -1;
}

int main() {
    cin >> n >> k;
    visited = vector<bool>(N, false);
    cout << bfs(n) << endl;
    
    return 0;
}