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

typedef pair<int, int> PII;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
    idx ++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist); // 初始化每个点到第一个点的距离为最大值
    dist[1] = 0;                     // 1到1距离为0

    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1}); // 距离为0，编号为1的点

    while (heap.size())
    {
        // 弹出最小距离的点
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;
        if (st[ver]) continue; // 跳过已经确定最小值的

        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) // 遍历ver的邻接节点
        {
            int j = e[i];
            if (dist[j] > distance + w[i]) // 检查是否通过 t 到 j 的距离更短
            {
                dist[j] = distance + w[i]; // 更新 dist[j]
                heap.push({dist[j], j}); // 将更新后的节点 j 插入堆中（会有重复，但不要紧，因为每次都优先弹出距离最小的）
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
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

    int t = dijkstra();

    cout << t << endl;

    return 0;
}