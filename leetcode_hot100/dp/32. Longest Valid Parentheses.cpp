class Solution {
public:
    // 思路特别难想
    // 括号序列的合法条件：1. 左右括号数量相等 2. 任意前缀中，右括号数量<=左括号数量（有未来匹配的潜力）
    int longestValidParentheses(string s) {
        stack<int> st;
        int res = 0;
        // 在[start~i]中找一段有效闭合区间
        for (int i = 0, start = -1; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else { // s[i] == ')'
                if (st.size()) { // 如果存在匹配的'('，弹出
                    st.pop(); 
                    if (st.size()) {
                        int left = st.top();
                        res = max(res, i - left); // start之后有'('尚未被匹配，但未来还有机会
                    } else {
                        res = max(res, i - start); // start之后的'('至此已经完全匹配，全部count
                    }
                } else { // 如果不存在匹配的‘（’，说明右括号多于左括号，序列失效，开始扫描下一段区间
                    start = i;
                }
            }
        }
        return res;
    }
};