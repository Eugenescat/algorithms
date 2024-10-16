#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 3;

int h[N];
int e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N; // 因为−1e9≤x≤1e9，所以(x+N)%N可能还是负数，不行
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
            
    return false;
}

int main()
{
    int n;
    cin >> n;
    
    // -1 表示每个字节都被设置为 0xFF 
    // 这行代码的作用是将数组 h 的每个字节都初始化为 0xFF。
    // 如果 h 是一个整数数组，由于每个整数通常是由多个字节组成（比如在 32 位系统中，一个 int 是 4 个字节），
    // 这意味着每个整数都会被设置为 -1（因为 0xFFFFFFFF 转换为有符号整型是 -1）
    memset(h, -1, sizeof h); // 初始化h数组，如果不初始化会导致陷入无限循环
    
    while (n--)
    {
        char op[2];
        int x;
        cin >> op >> x;
        
        if (op[0] == 'I') insert(x);
        else {
            if (find(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}


