#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int m;
int e[N], l[N], r[N], idx;

// 初始化
void init()
{
    // 0表示左端点，1表示右端点，这两个是保留字
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 表示在第k个插入的数右侧插入一个数
void add_r(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k], l[idx] = k;
    l[r[k]] = idx, r[k] = idx; // 注意调整l[r[k]]和r[k]的顺序
    idx ++;
}

// 表示在第k个插入的数左侧插入一个数
void add_l(int k, int x)
{
    add_r(l[k], x);
}

// 表示在链表的最左端插入数 x
void leftmost(int x)
{
    add_r(0, x);
}

// 表示在链表的最右端插入数 x
void rightmost(int x)
{
    add_r(l[1], x);
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    cin >> m;

    init();

    while (m -- )
    {
        string op;
        cin >> op;
        int k, x;
        if (op == "L")
        {
            cin >> x;
            leftmost(x);
        }
        else if (op == "R")
        {
            cin >> x;
            rightmost(x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1); // 双链表的起始点是2. 所以，每个插入位置k的真实位置应该为 k-1+2 = k+1 (在单链表中为 k-1)。
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            add_l(k + 1, x); // 同上
        }
        else
        {
            cin >> k >> x;
            add_r(k + 1, x); // 同上
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    cout << endl;

    return 0;
}

