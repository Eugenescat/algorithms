#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20010;

int n, m;
int f[N], g[N];
deque<int> dq;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) // 遍历物品
    {
        int v, w, s;
        cin >> v >> w >> s;

        memcpy(g, f, sizeof f); // g 是 f 的备份（上一轮的值）

        for (int j = 0; j < v; j++) // 一组步长内（它们可以共用一个队列）
        {
            dq.clear();
            for (int k = j; k <= m; k += v) // 以v为步长遍历k (每个group中的对应位置)
            {
                // 判断队头是否过期（超过 s 件）
                if (!dq.empty() && dq.front() < k - s * v) dq.pop_front();
                
                // 维护单调性：递减队列
                while (!dq.empty() && g[dq.back()] - (dq.back()-j)/v * w <= g[k] - (k-j)/v * w) dq.pop_back();
                
                dq.push_back(k);
                
                // 采用单调队列中的最大值
                int p = dq.front();
                f[k] = g[p] + (k-p)/v * w;
            }
        }
    }

    cout << f[m] << endl;
    return 0;
}
