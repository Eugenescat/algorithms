#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n; // 输入数组的长度
int q[N]; // 输入的数组

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    // x是随机取的基准值，i和j在范围外两侧
    // 注意这里x的取值和最后(i-1, i)或者(j, j+1)有联动关系，x=q[l]和(i-1, i)互斥，x=q[r]和(j, j+1)互斥，因为可能会在黏着边界的区间产生无限递归循环的问题
    int x = q[(l + r + 1) / 2], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (q[i] < x); // 先向右挪动i，只要q[i]<x就会继续挪动，因此最终i所指的数将>=x
        do j--; while (q[j] > x); // 先向左挪动j，只要q[j]>x就会继续挪动，因此最终j所指的数将<=x
        // 如果此时i和j并未相遇，将两指针所指的数交换即可
        // 如果i和j此时重叠或紧密交叉，循环将终止
        if (i < j) swap(q[i], q[j]); 
        // 每次循环开始前可以保证q[i]和i左侧的数都<=x，q[j]和j右侧的数都>=x
    }
    // 循环结束时，可以保证i左侧<=x，j右侧>=x
    quick_sort(q, l, i - 1);
    quick_sort(q, i, r);
    // 注意这里不能是i和i+1的搭配，因为i是从左向右移动，i-1是安全的，i+1是不安全的，可能产生数组越界访问
    // 另一个等效版本
    // quick_sort(q, l, j);
    // quick_sort(q, j + 1, r);
    // 同理这里j+1是安全的，而j-1是不安全的
}

int main()
{
    // 扫描输入
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", q[i]);

}