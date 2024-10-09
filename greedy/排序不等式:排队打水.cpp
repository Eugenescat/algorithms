#include <iostream>  
#include <algorithm> 

using namespace std;

typedef long long LL; // 定义 LL 为 long long 类型的别名，用于表示较大的整数

const int N = 100010;

int n;      // 用于存储输入的整数数量
int t[N];   // 定义一个整数数组 t，用于存储输入的数值

int main()
{
    // 输入整数 n，表示数组中的元素数量
    scanf("%d", &n);

    // 循环读取 n 个整数，并存储到数组 t 中
    for (int i = 0; i < n; i++) 
        scanf("%d", &t[i]);

    // 对数组 t 进行升序排序
    sort(t, t + n);

    LL res = 0; // 用于存储最终的结果，使用 long long 类型以避免整数溢出

    // 遍历数组 t，将每个元素乘以其在数组中的索引，并累加到结果 res 中
    for (int i = 0; i < n; i++)
        res += t[i] * (n-i-1);

    cout << res << endl;

    return 0; // 返回 0，表示程序正常结束
}
