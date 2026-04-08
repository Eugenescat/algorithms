#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << 10, K = 110;

int n, m;
vector<int> state; // 存储所有合法的状态
int cnt[M]; // cnt[i]表示状态i中1的个数
vector<int> head[M]; // 头指针，表示状态i可以转移到的状态j
LL f[N][K][M];

bool check(int state) // 状态中是否存在连续的两个1
{
    for (int i = 0; i < n; i ++ )
        if ((state >> i & 1) && (state >> i + 1 & 1)) // 当前位和前一位都是1
            return false;
    return true;
}

int count(int state) // 统计状态中1的个数
{
    int res = 0;
    for (int i = 0; i < n; i ++ ) res += state >> i & 1;
    return res;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < 1 << n; i ++ ) // (1 << n)表示所有可能的状态
        if (check(i)) // 如果状态i合法（代表某一行i的合法排布）
        {
            state.push_back(i); // 将状态加入state数组
            cnt[i] = count(i); // 统计状态i中1的个数
        }
    
    for (int i = 0; i < state.size(); i ++ )
        for (int j = 0; j < state.size(); j ++ )
        {
            int a = state[i], b = state[j]; // a和b分别表示两行的状态
            if ((a & b) == 0 && check(a | b)) // 如果两行状态没有重叠且合并后也没有相邻的1
                head[i].push_back(j); // 状态i可以转移到状态j
        }

    f[0][0][0] = 1; // 初始状态，什么都不摆，合法方案数为1
    for (int i = 1; i <= n + 1; i ++ ) // 枚举行
        for (int j = 0; j <= m; j ++ ) // 枚举当前已经摆了j个1
            for (int a = 0; a < state.size(); a ++ ) // 枚举当前行的合法状态（遍历state数组）
                for (int b : head[a]) // 所有可以合法转移到当前行的状态b
                {
                    int current = cnt[state[a]]; // 当前行状态中1的个数
                    if (j >= current) // 如果当前已经摆了j个1，且当前行状态中1的个数不超过j
                        f[i][j][a] += f[i - 1][j - current][b];
                }

    // 为什么要遍历到n + 1行？
    // 用最后一行表示一个虚拟行（状态为0，且已经摆了j个国王），将所有状态收束到这个状态，比较方便
    cout << f[n + 1][m][0] << endl;

    // 否则这样表示也可以：
    // LL res = 0;
    // for (int i = 0; i < state.size(); i++) res += f[n][m][i];
    // cout << res << endl;

    return 0;
}