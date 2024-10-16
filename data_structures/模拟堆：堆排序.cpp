#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], sz;

void down(int u)
{
    int t = u;
    if (u * 2 <= sz && h[u * 2] < h[t]) t = u * 2; // 和u的左子节点比较
    if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1; // 和u的右子节点比较
    if (u != t) // 如果可以成功下移到左子节点或者右子节点
    {
        swap(h[u], h[t]); // 将u和该子节点互换
        down(t);
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> h[i]; // 先放进数组形成一个完全二叉树（乱序的）
    sz = n;
    
    for (int i = n/2; i; i--) down(i); // 从最后一个非叶子结点开始向下down
    
    while (m--)
    {
        cout << h[1] << " ";
        h[1] = h[sz];
        sz --;
        down(1);
    }
}