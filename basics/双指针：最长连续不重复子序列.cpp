#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], s[N];

// s[N]是一个类似哈希表的东西

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        s[a[i]] ++;
        // 检查新来的a[i]和之前是否有重复
        while (j < i && s[a[i]] > 1)
        {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    
    printf("%d", res);
    
    return 0;
}