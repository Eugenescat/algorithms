#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010; // 定义一个常量 N，表示区间数组的最大长度

int n; // 用于存储区间的数量

// 定义一个结构体 Range，用于表示一个区间
struct Range
{
    int l, r; // 区间的左端点 (l) 和右端点 (r)

    // 重载小于运算符，使得可以按照右端点来比较两个区间
    // 在使用排序算法时，会根据区间的右端点进行排序
    bool operator< (const Range &W) const
    {
        return r < W.r; // 当当前区间的右端点小于另一个区间的右端点时，返回 true
    }
} range[N]; // 定义一个 Range 类型的数组，大小为 N，用于存储多个区间

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;
    
    sort(range, range + n);
    
    int res = 0, ed = -2e9;
    for (int i = 0; i < n; i++)
        if (range[i].l > ed)
        {
            res ++;
            ed = range[i].r;
        }
        
    cout << res << endl;
    
    return 0;
}