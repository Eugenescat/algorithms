#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, k;
int a[N], q[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    int hh = -1, tt = -1;
    // 最小值：维护一个严格单调递增的双端队列
    for (int i = 0; i < n; i++)
    {
        // 判断队头是否已经滑出窗口，如果是则把超出窗口的下标删掉
        if (hh < tt && (i - k + 1) > q[hh + 1]) hh++;
        // 当队列尾顶大于等于新元素时，去掉尾顶，直到队列尾顶小于新元素
        while (hh < tt && a[q[tt]] >= a[i]) tt --;
        
        q[++tt] = i; // 应该先将i放进队列再从队列中打印最小值，因为i可能是最小值
        if (i >= k - 1) printf("%d ", a[q[hh + 1]]);
    }
    
    puts("");
    
    hh = -1, tt = -1;
    // 最大值：维护一个严格单调递减的双端队列
    for (int i = 0; i < n; i++)
    {
        // 判断队头是否已经滑出窗口，如果是则把超出窗口的下标删掉
        if (hh < tt && (i - k + 1) > q[hh + 1]) hh++;
        // 当队列尾顶小于等于新元素时，去掉尾顶，直到队列尾顶大于新元素
        while (hh < tt && a[q[tt]] <= a[i]) tt --;
        
        q[++tt] = i; // 应该先将i放进队列再从队列中打印最大值，因为i可能是最大值
        if (i >= k - 1) printf("%d ", a[q[hh + 1]]);
    }
    
    puts("");
    
    return 0;
}
