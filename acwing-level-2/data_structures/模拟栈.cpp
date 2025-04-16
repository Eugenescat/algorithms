#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int m;
int stk[N], tt; // tt是栈点下标

int main()
{
    cin >> m;
    
    // 初始化
    tt = 0;
    
    while (m--)
    {
        string op;
        int x;
        cin >> op;
        // push x，pop，empty，query
        if (op == "push")
        {
            cin >> x;
            stk[ ++ tt] = x; // 插入
        }
        else if (op == "pop") tt --; // 删除
        else if (op == "empty") 
        {
            // 判断栈是否为空
            if (tt > 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else cout << stk[tt] << endl; // 查询栈顶元素
    }
}
