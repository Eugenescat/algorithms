#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 12, M = 1 << N; // N 表示棋盘的列数上限，M = 1 << N 是所有列状态的可能数目

int n, m; // n 表示棋盘的列数，m 表示棋盘的行数
long long f[N][M]; // f[i][j] 表示填到第 i 行时，列状态为 j 的方案数
bool st[M]; // st[i] 用于判断状态 i 是否满足条件，即该状态能否由完整的骨牌填充

int main()
{
    while (cin >> n >> m, n || m) // 输入棋盘的列数 n 和行数 m，直到 n 和 m 都为 0 时停止
    {
        // 初始化所有可能的列状态，判断状态是否可以被完整覆盖
        for (int i = 0; i < 1 << n; i++) // 遍历所有列状态，状态 i 的范围是 0 到 2^n - 1
        {
            int cnt = 0; // 计数器，用于检查连续的 0 的个数
            st[i] = true; // 假设状态 i 默认是合法的
            for (int j = 0; j < n; j++) // 遍历状态 i 的每一位
                if (i >> j & 1) // 检查状态 i 的第 j 位是否为 1
                {
                    if (cnt & 1) st[i] = false; // 如果连续 0 的数量是奇数，则状态非法
                    cnt = 0; // 重置计数器
                }
                else cnt++; // 如果当前位是 0，增加连续 0 的计数
            if (cnt & 1) st[i] = false; // 最后一个连续 0 的数量如果是奇数，则状态非法
        }

        memset(f, 0, sizeof f); // 将状态数组 f 初始化为 0
        f[0][0] = 1; // 初始条件：在第 0 行，列状态为 0 的情况只有 1 种

        // 动态规划求解填满棋盘的方案数
        for (int i = 1; i <= m; i++) // 遍历每一行
            for (int j = 0; j < 1 << n; j++) // 遍历当前行的每个列状态 j
                for (int k = 0; k < 1 << n; k++) // 遍历上一行的每个列状态 k
                    if ((j & k) == 0 && st[j | k]) // 如果 j 和 k 状态不重叠且合并后的状态合法
                        f[i][j] += f[i - 1][k]; // 累加前一行的方案数

        cout << f[m][0] << endl; // 输出填满整个棋盘的方案数，即 m 行棋盘最后一行状态为 0 的方案数
    }
    return 0;
}
