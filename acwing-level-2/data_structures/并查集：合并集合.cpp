#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];

// 路径压缩：不仅能找到x的根节点，还能在每层递归返回时让中间的每个节点都指向x的根节点
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i <= n; i ++) p[i] = i;

    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M') p[find(a)] = find(b); // 将a的根节点和b的根节点连起来
        else
        {
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}