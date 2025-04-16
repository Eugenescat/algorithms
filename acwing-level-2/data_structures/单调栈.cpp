#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, stk[N], tt = 0; // 可以不需要专门做一个ans[]，直接即时cout

int main()
{
    cin >> n;
    
    // 注意不要把i(下标)和x(下标为i的元素的值)搞混了，入栈的是x
    for (int i = 0; i < n; i++) // 挨个入栈
    {
        int x;
        cin >> x;
        // 当栈顶元素大于等于新入栈的元素x时，扔掉栈顶元素，直到栈顶元素小于新元素x。注意tt大于0
        while (tt && stk[tt] >= x) tt--;
        // 如果栈顶元素小于新元素x，该栈顶元素就是所求的“左边第一个比它小的数”
        if (tt) cout << stk[tt] << ' '; // tt必须不为0，如果为0就说明栈中元素已经全部弹出，不存在比x小的数
        else cout << -1 << ' ';
        
        // 最后别忘了把x插入栈
        stk[++tt] = x;
    }
    
    return 0;
}