#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10; // 常量 N 定义为 10，用于处理 0-9 的数字

/* 函数功能：统计数字在不同位数上的出现次数
 *
 * count 函数逻辑：计算一个整数 n 中数字 x 在各个位数上出现的次数。
 * 使用了辅助函数 get 和 power10 进行数字提取和十进制数幂次计算。
 */

int get(vector<int> num, int l, int r)
{
    int res = 0;
    // 从高位到低位遍历，将每一位数字累加到结果中
    for (int i = l; i >= r; i--) 
        res = res * 10 + num[i]; // 将数字逐位添加到 res 中，形成一个完整的数字
    return res; // 返回由 l 到 r 组成的数字
}

int power10(int x)
{
    int res = 1;
    // 计算 10 的 x 次方，用于数位计算
    while (x--) 
        res *= 10; // 每次乘以 10
    return res; // 返回 10 的 x 次方
}

int count(int n, int x)
{
    if (!n) return 0; // 如果 n 为 0，则数字 x 在 n 中出现次数为 0

    vector<int> num;
    // 将整数 n 转换为一个数组 num，数组中每个元素是 n 的一位数字
    while (n)
    {
        num.push_back(n % 10); // 将 n 的最低位添加到 num 数组中
        n /= 10; // 去掉最低位
    }
    n = num.size(); // 更新 n 为 num 的长度，即 n 的位数

    int res = 0; // 用于记录数字 x 在 n 中出现的次数
    // 从高位到低位遍历数字 n 的每一位，跳过不处理 x == 0 的最高位情况
    for (int i = n - 1 - !x; i >= 0; i--)
    {
        // 如果不是最高位时，计算数字 x 在当前位数之前的出现次数
        if (i < n - 1)
        {
            res += get(num, n - 1, i + 1) * power10(i); // 计算当前位之前的所有情况
            if (!x) res -= power10(i); // 如果 x 是 0，减去不符合条件的情况
        }

        // 处理当前位是否等于 x 的情况
        if (num[i] == x) 
            res += get(num, i - 1, 0) + 1; // 如果当前位等于 x，则加上低位的情况
        else if (num[i] > x) 
            res += power10(i); // 如果当前位大于 x，则加上所有符合条件的情况
    }

    return res; // 返回数字 x 在数字 n 中出现的总次数
}

int main()
{
    int a, b;
    // 读取两个整数 a 和 b，计算 a 到 b 范围内每个数字出现的次数
    while (cin >> a >> b, a)
    {
        if (a > b) swap(a, b); // 确保 a 小于或等于 b

        // 对每个数字 0 到 9，分别计算它在 a 到 b 范围内出现的次数
        for (int i = 0; i <= 9; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl; // 输出每个数字在区间内出现的次数
    }

    return 0;
}
