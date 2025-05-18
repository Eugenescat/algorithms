#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55, mod = 1e9 + 7;

int n, m;
char str[N];
int nxt[N];
int f[N][N]; // 已经构造了长度为 i 的字符串，当前匹配到了 `str` 的前 j 个字符（KMP自动机状态是 j），的合法方案数。

int main()
{
    cin >> n >> str + 1;

    m = strlen(str + 1);

    // 求next数组的过程
    for (int i = 2, j = 0; i <= m; i ++ )
    {
        while (j && str[i] != str[j + 1]) j = nxt[j];
        if (str[i] == str[j + 1]) j ++ ;
        nxt[i] = j;
    }

    // 表示长度为 0 的字符串，当前没有匹配任何模版串前缀，合法方案数是 1
    f[0][0] = 1;
    // 枚举长度为i的字符串，当前匹配到模版串的下标j（m是模版串p长度）
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            // 枚举下一个加哪个字符k(即 s[i + 1])
            for (char k = 'a'; k <= 'z'; k ++ )
            {
                int u = j;
                while (u && k != str[u + 1]) u = nxt[u]; // 努力找到能匹配k的模版串位置
                if (k == str[u + 1]) u ++;
                // 如果你尚未匹配完整个 str（u < m）, 那就可以合法转移，把当前方案数计入 f[i+1][u]
                if (u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod; // 多个状态可能都转移到同一个f[i + 1][u]，所以需要加上其本身
            }

    int res = 0;
    // 把所有长度为n且在模版串中匹配了0~(m-1)个字符的方案数加起来
    for (int i = 0; i < m; i ++ ) res = (res + f[n][i]) % mod;

    cout << res << endl;

    return 0;
}