#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx; // 邻接表，比模版多了一个w[N]表示某条边的权重
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
    idx ++;
}

void spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j]) // 为什么如果st[j]就不再考虑呢，这次j不是又更新了吗
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << dist[n] << endl;
}

int main()
{
    cin >> n >> m;

    // 初始化为-1
    memset(h, -1, sizeof h);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c); // 用邻接表的话，重复边无所谓
    }

    spfa();

    return 0;
}