#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 3e5 + 10; // 为什么离散化有3e5:插入操作n有1e5，查询操作m有1e5，查询操作中包括l和r两个坐标，一共是3e5

int n, m;
int a[N], s[N]; // a是压缩后的数组，s是前缀和数组

vector<int> alls; // 保存x,l,r的整数索引集
vector<PII> add, query;

int find(int x) // 找到alls中>=x的最小的数，返回的是该数在alls中压缩映射后的坐标
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c}); // 把改变的坐标和对应增加的数字pair放进add[]数组
        
        alls.push_back(x); // 把改变的坐标加入待离散化的alls
    }
    
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r}); // 把左右区间坐标pair放进query[]数组
        
        alls.push_back(l); // 把左右区间坐标依次加入待离散化的alls
        alls.push_back(r);
    }
    
    // 对alls数组排序和去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    // a[]
    for (auto item : add)
    {
        int x = find(item.first); // 找到x在离散化后alls中的新坐标
        a[x] += item.second; // 向a[]的新坐标中加入c数值
    }
    
    // 计算a[]的前缀和s[]
    for (int i  = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];
    
    // 处理询问
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
}

