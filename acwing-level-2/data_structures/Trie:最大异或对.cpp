// 因为每个数都小于2^31，所以每个数可以看成长度为31位的二进制数
// 异或的结果是1^1=0,0^0=0,1^0=1;
// 时间复杂度 31*1e5，nlogn，一秒内出结果
// 时间控制在1e7~1e8最好

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = 31 * N; // 一共N个数，每个数需要31个节点

int n;
int a[N];
int son[M][2]; // 这次只有0和1两种子节点
// int cnt[N]; 这道题不需要维护该节点是否有字符串结束了
int idx;


void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1; // 用于提取整数 x 的二进制表示中第 i 位的值
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

// 返回当前数在trie中找到的最大异或对
int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1; // 用于提取整数 x 的二进制表示中第 i 位的值
        // 尝试找到与当前位异或结果为1的分支，即!u
        if (son[p][!u])
        {
            res = res * 2 + !u; // 该路径目前为止的值
            p = son[p][!u]; // 向下走到相反的子节点
        }
        else
        {
            res = res * 2 + u;
            p = son[p][u];
        }
    }
    
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    
    int res = 0;
    for (int i = 0; i < n; i ++) res = max(res, query(a[i]) ^ a[i]);
    
    cout << res;
    
    return 0;
}

