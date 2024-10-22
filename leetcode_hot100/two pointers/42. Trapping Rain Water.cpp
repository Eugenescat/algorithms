class Solution {
public:
    // 思路：维护一个单调递减的栈（下标入栈），每次遇到一个比栈顶高的柱子，就一层层加上接到的雨水，直到将该柱子加入单调栈
    // 一层层相加时需要额外维护上一层水位的高度
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i ++)
        {
            int last = 0;
            // 如果当前柱子比栈顶高，以栈顶的高度为基准一层层不断加入
            while (stk.size() && height[stk.top()] < height[i])
            {
                int k = stk.top();
                res += (i - k - 1) * (height[k] - last);
                stk.pop();
                last = height[k];
            }
            // 如果栈中还剩下比当前柱子高的（或者柱子一开始就比栈顶矮），不要忘掉加上以当前柱子为高度的最后一层
            if (stk.size())
            {
                int k = stk.top();
                res += (i - k - 1) * (height[i] - last);
            }
            stk.push(i);
        }
        return res;
    }
};