class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> stk;
        vector<int> res(t.size());

        // 从后往前构建单调栈
        for (int i = t.size() - 1; i >= 0; i --) {
            // 保持单调性，弹出比当前温度低的
            while (stk.size() && t[i] >= t[stk.top()]) stk.pop();
            // 如果栈中之前还有比当前更高的温度
            res[i] = stk.size()? stk.top() - i : 0;
            stk.push(i);
        }

        return res;
    }
};