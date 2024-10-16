#include <iostream>

using namespace std;

const int N = 1e5 + 10; // 定义常量N为100010，表示Trie树中最多的节点数

int son[N][26]; // son数组，用于存储每个节点的子节点。数组第一维表示节点编号，第二维表示26个可能的子节点（对应26个英文字母）
int cnt[N];     // cnt数组，用于记录以每个节点为结尾的字符串数量
int idx;        // idx变量，用于记录当前Trie树中已经使用到的节点编号的最大值

void insert(char str[]) // 插入函数，参数为待插入的字符串
{
    int p = 0; // p变量从根节点（编号为0）开始
    for (int i = 0; str[i]; i++) // 遍历字符串中的每个字符
    {
        int u = str[i] - 'a'; // 将当前字符转换为0-25的索引，对应a-z
        if (!son[p][u]) son[p][u] = ++idx; // 如果当前节点p没有指向字符str[i]的子节点，则创建一个新节点（节点编号+1）存入son[p][u]
        p = son[p][u]; // p指向新节点（如果节点已经存在指向字符str[i]的子节点，p就直接指向该节点）
    }
    
    cnt[p]++; // 在字符串结束的节点处，增加计数，表示这个节点是某个字符串的结尾
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    
    while (n--)
    {
        char op;
        char str[N];
        cin.ignore();
        cin >> op >> str;
        if (op == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    
    return 0;
}

