#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;
    
    sort(segs.begin(), segs.end()); // 按区间左端点排序
    
    int st = -2e9, ed = -2e9; // 类似于INT_MIN?
    for (auto seg : segs)
        if (ed < seg.first) // 情形三：当前区间和seg无交集
        {
            if (st != -2e9) res.push_back({st, ed}); // 如果当前区间不是初始化区间，就把当前区间加入集合
            st = seg.first, ed = seg.second; // 把seg区间作为当前区间
            
        }
        else ed = max(ed, seg.second); // 情形一：内包含；情形二：一端内一端外
        
    if (st != -2e9) res.push_back({st, ed}); // 收尾最后的区间。注意有可能题目给的是空集，避免把初始化区间加入集合
    
    segs = res;
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    
    merge(segs);
    
    cout << segs.size() << endl;
    
    return 0;
}