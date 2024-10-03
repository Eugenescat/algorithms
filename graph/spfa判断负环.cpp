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
int cnt[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
    idx ++;
}

bool spfa()
{
    // 本题求有没有负环，不用求距离，所以不需要初始化了，用cnt[]来维护到达某个点经过的点总数量
    // memset(dist, 0x3f, sizeof dist);
    // dist[1] = 0;

    // 本题需要把每个点都放到queue里，因为只从1开始可能经过不了负环。但把所有点都处理一遍一定能找到负环。
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }

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

                // 每次检查一下到达j的点是否超过n了，如果大于等于n就说明中间有负环了
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;

                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
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

    if(spfa()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}