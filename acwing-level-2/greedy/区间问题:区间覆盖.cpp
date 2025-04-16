#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;

struct Range
{
    int l, r;
    bool operator< (const Range& w)const
    {
        return l < w.l;
    }
}range[N];

int main()
{
    int st, ed; // 定义起始点 st 和结束点 ed，用于表示目标区间
    cin >> st >> ed;
    cin >> n;

    // 读取每个区间的左端点和右端点，并存储到 range 数组中
    for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;

    // 使用 sort 函数对区间数组进行排序，按照左端点升序排列
    sort(range, range + n);

    int res = 0;          // 记录最少的区间数
    bool success = false; // 标志位，表示是否成功覆盖了目标区间

    // 遍历排序后的区间数组
    for (int i = 0; i < n; i++)
    {
        int j = i, r = -2e9; // 初始化 j 为当前区间的索引，r 为当前能覆盖到的最远右端点

        // 扫描所有左端点在st左侧的区间，找出其中右端点最远的1个区间
        while (j < n && range[j].l <= st)
        {
            r = max(r, range[j].r); // 更新最远的右端点 r
            j++;
        }

        // 如果最远右端点小于当前的起始点，说明无法继续覆盖区间
        if (r < st)
        {
            res = -1; // 设置结果为 -1，表示无法覆盖整个目标区间
            break; // 退出循环
        }

        res++; // 将当前区间加入覆盖区间

        // 如果已经覆盖到了目标区间的结束点 ed，则说明成功覆盖整个区间
        if (r >= ed)
        {
            success = true; // 设置成功标志位
            break; // 退出循环，因为已经找到了答案
        }

        st = r; // 更新起始点为当前能覆盖的最远右端点
        i = j - 1; // 更新循环索引，跳过已经处理过的区间
    }

    // 如果遍历完所有区间，仍然没有成功覆盖目标区间，则设置结果为 -1
    if (!success) res = -1;
    printf("%d\n", res); // 输出最终的结果，表示最少需要的区间数量

    return 0; // 程序正常结束
}