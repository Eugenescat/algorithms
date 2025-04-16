#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int m;
int que[N], hh, tt; // hh是队尾下标，tt是队头下标

int main()
{
    cin >> m;

    // 初始化 注意这里不能写hh, tt = -1 这样会错误地只初始化了tt
    hh = -1, tt = -1;

    while (m--)
    {
        string op;
        int x;
        cin >> op;
        // push x，pop，empty，query
        if (op == "push")
        {
            cin >> x;
            que[ ++ tt] = x; // 队尾插入
        }
        else if (op == "pop") hh ++; // 队头删除
        else if (op == "empty") 
        {
            // 判断栈是否为空
            if (tt > hh) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else cout << que[hh + 1] << endl; // 查询队头元素。注意hh本身并不指向队列元素，它是队列外的无值尾巴
    }
}