#include <iostream>

using namespace std;

const int N = 100010;

// 用struct构造node太慢了，所以用数组模拟单链表(邻接表常用)
// 用e[N] ne[N]分别表示N节点的值和指向N节点next节点的指针
// idx用于存储当前可用哪个点
int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0; // 当前可以从0开始分配
}

// 将x插到头节点
void add_to_head(int x)
{
    e[idx] = x; // 将当前可分配节点的值设为x
    ne[idx] = head; // next指向原来的head下标
    head = idx; // idx成为新head下标
    idx ++; // 可分配节点（可以用来表示第idx个插入的数）
}

// 将x插到下标是k的这个点后面
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++; // 
}

// 将x插到下标是k的这个点后面删掉
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin >> m; //操作次数
    
    init();
    
    while (m --)
    {
        int k, x;
        char op;
        
        cin >> op; 
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if(op == 'D')
        {
            cin >> k;
            // 当k为0时，表示删除头结点
            if (!k) head = ne[head];
            remove(k-1); // 第k个插入的数的下标是k-1
        }
        else
        {
            cin >> k >> x;
            add(k-1, x); // 第k个插入的数的下标是k-1
        }
    }
    
    // 打印
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    
    return 0;
}