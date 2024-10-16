#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int q[N], temp[N];

LL merge_sort(int l, int r)
{
    if (l >= r ) return 0;
    
    int mid = l + r >> 1;
    LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);
    
    // merge
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
        if (q[i] <= q[j]) temp[k++] = q[i++];
        else
        {
            temp[k++] = q[j++];
            // 根据排序目的，q[i]之前的数一定小于q[j]，q[j]之后的数一定大于q[j]
            // 如果q[i]>q[j]，则q[i]之后的数一定大于q[j]
            // 因此，q[j]的逆序对数量就是q[i]之后\mid点之前的数总数
            res += mid - i + 1;
        }
    }
    // 扫尾
    while (i <= mid) temp[k++] = q[i++];
    while (j <= r) temp[k++] = q[j++];
    
    // 物归原主（在临时数组Merge完后，覆盖原q[]）
    // 注意临时数组temp[k]从0开始，q[i]从传入参数Index = l开始
    for (int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
    
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    cout << merge_sort(0, n - 1) << endl;
}