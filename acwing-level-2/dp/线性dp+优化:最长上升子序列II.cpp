#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;        // 变量 n 表示输入序列的长度
int a[N];     // 数组 a 用于存储输入序列
int q[N];     // 数组 q 用于维护一个递增序列，n表示子序列长度，q[n]表示结尾的数（同一长度下只保存最小的那个子序列）

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

        // 找到q[n]中结尾数小于a[i]的最大子序列
        // 即：找到 q[n] 中最后一个小于 a[i] 的位置
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;  
            if (q[mid] < a[i])           
                l = mid;                 
            else
                r = mid - 1;             
        }

        len = max(len, r + 1);  // 更新递增序列的长度 len，如果新的插入位置 r + 1 超出了当前长度
        q[r + 1] = a[i];        // 将a[i]更新到q[n]的r+1位置上
    }

    cout << len << endl;  // 输出构建的递增序列的最终长度
    return 0;
}
