#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], sz;
int ph[N], hp[N]; // ph是第k个插入的点的下标，hp是下标为t的点是第几个插入的

void heap_swap(int a, int b) // 用来追踪第k个插入的数
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= sz && h[u * 2] < h[t]) t = u * 2; // 和u的左子节点比较
    if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1; // 和u的右子节点比较
    if (u != t) // 如果可以成功下移到左子节点或者右子节点
    {
        heap_swap(u, t); // 将u和该子节点互换
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        heap_swap(u/2, u);
        u /= 2;
    }
}

int main()
{
    int n;
    int m = 0;
    cin >> n;
    
    while (n--)
    {
        char op[10];
        int k, x;
        
        cin >> op;
        if (!strcmp(op, "I"))
        {
            cin >> x;
            sz ++;
            m ++;
            ph[m] = sz, hp[sz] = m;
            h[sz] = x;
            up(sz);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, sz);
            sz -- ;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, sz);
            sz -- ;
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }
}