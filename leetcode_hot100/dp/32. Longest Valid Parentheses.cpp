class Solution {
public: 
    // 思路特别难想
    // 括号序列的合法条件：1. 左右括号数量相等 2. 任意前缀中，左括号数量>=右括号数量
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        // 在[start~i]中找一段有效闭合区间
        for (int i = 0, start = -1; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i); // 压入下标
            else {
                // 如果s[i]是右括号，就将栈中的最后一个左括号弹出
                // 如果栈中没有对应左括号，说明当前区间不满足括号序列的第二个合法条件，开始扫描下一个区间
                if (stk.size()) {
                    stk.pop();
                    // 有效区间从剩下的stk.top()的右侧开始 到当前i为止
                    // 如果栈已经空了，就是从当前区间的起点(start的右侧)开始 到当前i为止
                    if (stk.size()) {
                        int left = stk.top();
                        res = max(res, i - left);
                    }
                    else res = max(res, i - start);
                } else {
                    start = i; // 开始扫描下一段区间
                }
            }
        }
        return res;
    }
};