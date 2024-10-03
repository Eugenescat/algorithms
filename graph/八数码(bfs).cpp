#include <iostream>
#include <cstring>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string start)
{
    string end = "12345678x";
    
    queue<string> q;
    unordered_map<string, int> d;
    
    q.push(start);
    d[start] = 0;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        
        int distance= d[t];
        
        if (t == end) return distance;

        // 状态转移
        int k = t.find('x'); // 用string的find特性找出x的坐标
        int x = k / 3, y = k % 3; // 把一维数组下标转化为3x3矩阵的坐标

        for (int i = 0; i < 4; i ++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[k], t[a * 3 + b]); // 将t状态中两个格子的位置进行交换

                // 如果该新状态没有被访问过
                // d.count(t)：返回值是一个整数，它表示键 t 在哈希表 d 中出现的次数。在 unordered_map 中，键要么不存在，要么只会存在一次，因此 d.count(t) 的返回值要么是 0（不存在），要么是 1（存在）
                if (!d.count(t))
                {
                    // 将新状态记录下来，并设置距离为当前步数加 1
                    d[t] = distance + 1;
                    q.push(t); // 将新状态加入队列，等待后续处理
                }

                // 回溯
                swap(t[k], t[a * 3 + b]);
            }
        }
    }

    return -1;
}

int main()
{
    string start;
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        start += c;
    }
    
    cout << bfs(start) << endl;
    
    return 0;
}