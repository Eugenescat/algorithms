#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char p[N], s[M];
int ne[N]; // next[N]可能在某些头文件中被用过会报错，所以最好用ne[N]

int main()
{
    cin >> n >> p + 1 >> m >> s + 1; // 我们想从 p[1] 开始接收输入，忽略 p[0]
    
    // 求next的过程
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j+1]) j++;
        ne[i] = j;
    }
    
    // kmp匹配的过程
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j+ 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) // j走到了p[N]的尽头
        {
            // 匹配成功
            printf("%d ", i - n);
            j = ne[j];
        }
    }
    
    return 0;
}