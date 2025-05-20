#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

typedef pair<char, string> PII;

int n, k;
char g[2][4];
unordered_map<string, bool> visited; // 使用unordered_map来存储visited
unordered_map<string, PII> previous;

// 把string还原为数组
void decode(string state) {
    for (int i = 0; i < 4; i++) {
        g[0][i] = state[i];
    }
    for (int i = 0; i < 4; i++) {
        g[1][i] = state[7 - i];
    }
}

// 把数组还原为string
string encode() {
    string res;
    for (int i = 0; i < 4; i++) {
        res += g[0][i];
    }
    for (int i = 3; i >= 0; i--) {
        res += g[1][i];
    }
    return res;
}

string move0(string state) {
    decode(state);
    for (int i = 0; i < 4; i++) {
        swap(g[0][i], g[1][i]);
    }
    return encode();
}

string move1(string state) {
    decode(state);
    // 保存最后一列
    char v0 = g[0][3], v1 = g[1][3];
    // 把前三列的值往后移
    for (int i = 3; i > 0; i--) {
        g[0][i] = g[0][i - 1];
        g[1][i] = g[1][i - 1];
    }
    // 把最后一列的值放到第一列
    g[0][0] = v0;
    g[1][0] = v1;
    return encode();
}

// 魔板中央对的4个数作顺时针旋转
string move2(string state) {
    decode(state);
    // 保存中间的4个数
    char v0 = g[0][1], v1 = g[0][2], v2 = g[1][1], v3 = g[1][2];
    // 旋转
    g[0][1] = v2;
    g[0][2] = v0;
    g[1][1] = v3;
    g[1][2] = v1;
    return encode();
}

int bfs(string start, string target) {
    queue<string> q;
    q.push(start);
    visited[start] = true;
    int steps = 0;
    
    while (q.size()) {
        int sz = q.size();
        while (sz--) {
            string x = q.front();
            q.pop();
            if (x == target) return steps;

            string next[3];
            next[0] = move0(x);
            next[1] = move1(x);
            next[2] = move2(x);
            
            char d[3] = {'A', 'B', 'C'};
            for (int i = 0; i < 3; i++) {
                if (!visited[next[i]]) {
                    visited[next[i]] = true;
                    previous[next[i]] = {d[i], x}; // 记录前驱节点
                    q.push(next[i]);
                }
            }
        }
        steps ++;
    }
    
    return -1;
}

int main() {

    // 目标状态->编码
    int x;
    string target;
    for (int i = 0; i < 8; i++) {
        cin >> x;
        target += char(x + '0'); // 输入1，输出'1'。这里实际上是把'0'视为ascii码，并往后找下1个acii码
    }
    
    string start;
    // 构造基本状态
    for (int i = 1; i <= 8; i++) {
        start += char(i + '0');
    }

    cout << bfs(start, target) << endl;

    // 输出路径
    string cur = target;
    string path;
    while (cur != start) {
        path += previous[cur].first;
        cur = previous[cur].second;
    }
    reverse(path.begin(), path.end());
    cout << path << endl;

    return 0;
}