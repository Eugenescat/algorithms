class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                // 用ASCII码来判定是否为一对
                if (stk.size() && abs(stk.top() - c) <= 2) stk.pop();
                else return false;
            }
        }

        return stk.empty();
    }
};