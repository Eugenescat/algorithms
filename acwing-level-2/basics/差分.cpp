#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N], b[N];

// insert的逻辑是从l开始a[i]需要增加c，从r+1开始a[i]的元素不再需要增加c
void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]); // 输入数组（注意本题将该数组视为前缀和数组，故a[0]=0）
    
    // 根据a[N]，构造差分数组b[N]
    // 每个insert(i, i, a[i])操作实际上是在位置i上增加a[i]，因为之前b[]都是0，
    // 这相当于设置了b[i] = a[i] - a[i-1]（对于i=1, b[1] = a[1]，对于i>1, b[i]是由之后的累加还原a[i]）
    for (int i = 1; i <= n; i++) insert(i, i, a[i]); 
    while (m--)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c); // 对差分数组b[N]做操作
    }
    
    for (int i = 1; i <= n; i++) b[i] += b[i - 1]; // 将b[N]还原为前缀和数组
    
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    
    return 0;
}