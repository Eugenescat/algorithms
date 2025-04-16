#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n,m;
int p[N];
int cnt[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }
    
    // 将编号放进数组p中的每个位置
    
    while (m--)
    {
        char op[5];
        int a, b;
        scanf("%s", op);
        
        if (op[0] == 'C')
        {
            cin >> a >> b;
            if (find(a) == find(b)) continue; // 注意特判
            cnt[find(b)] += cnt[find(a)]; // 把a集合的size加到b集合上
            p[find(a)] = find(b); // 把在点 a和点 b之间连一条边，抽象成a和b的根节点相连
        }
        else if (op[1] == '1')
        {
            cin >> a >> b;
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else
        {
            cin >> a;
            printf("%d\n", cnt[find(a)]); // 通过a的根节点找到该集合的size
        }
    }
}