#include <iostream>
#include <cstring>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<char> op;

void eval()
{
    // 注意a和b顺序是反的！
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    
    int x;
    if (c == '+') x = a + b;
    if (c == '-') x = a - b;
    if (c == '*') x = a * b;
    if (c == '/') x = a / b;
    num.push(x);
}

int main()
{
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; // priority
    string str;
    cin >> str;
    
    for (int i = 0; i < str.size(); i++)
    {
        auto c = str[i];
        if (isdigit(c)) 
        {
            int val = 0;
            while (isdigit(str[i]))
            {
                val = val * 10 + (str[i] - '0');
                i++;
            }
            i--;
            num.push(val);
        }
        else if (c == '(') op.push(c);
        else if (c == ')')
        {
            // 把对象括号之后的所有表达式求值
            while (op.top() != '(') eval();
            op.pop();
        }
        else
        {
            // 如果栈顶连续有优先级更高的运算符，先将栈中的运算符求值，直到被'('阻碍或栈空
            while (op.size() && op.top()!= '(' && pr[op.top()] >= pr[c]) eval();
            op.push(c);
        }
    }
    
    while (op.size()) eval();
    cout << num.top() << endl;
    return 0;
}