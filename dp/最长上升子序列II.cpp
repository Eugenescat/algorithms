#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;        // 变量 n 表示输入序列的长度
int a[N];     // 数组 a 用于存储输入序列
int q[N];     // 数组 q 用于维护一个递增序列，通常用于动态更新当前最优解

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int len = 0;  // 用于记录当前递增序列的长度
    q[0] = -2e9;  // 初始化数组 q 的第一个位置为一个极小值，用作哨兵，便于后续比较

    // 遍历输入数组 a 中的每个元素，逐步构建递增序列
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len;  // 二分查找的初始边界设置为 [0, len]

        // 使用二分查找找到插入位置，确保插入后的序列依然递增
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;  // 计算中点。注意这是 (l + r + 1) / 2 的缩写，向上取中间值
            if (q[mid] < a[i])           // 如果 q[mid] 小于当前元素 a[i]
                l = mid;                 // 更新左边界 l，使得区间缩小到 [mid, r]
            else
                r = mid - 1;             // 否则，更新右边界 r 为 mid - 1
        }

        // 更新递增序列的长度 len，如果新的插入位置 r + 1 超出了当前长度
        len = max(len, r + 1);  // r + 1 是当前元素将插入的位置
        q[r + 1] = a[i];        // 将当前元素 a[i] 插入到维护数组 q 的合适位置
    }

    cout << len << endl;  // 输出构建的递增序列的最终长度
    return 0;
}
