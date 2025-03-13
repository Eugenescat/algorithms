class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> left, right; // 用两个单调栈求每个数左边和右边第一个比它小的数
        vector<int> l(n), r(n); // 左右两侧第一个比它矮的柱子
        int res = 0;

        // 从左往右维护一个单调递增序列（如果出现了新的更小的柱子，之前的就不需要了）
        for (int i = 0; i < n; i++) {
            // 注意这里需要pop掉>=的，比如出现[1,2...]+2的时候，正确的l[i] = 1而不是2，需要把重复的2 pop出去
            while (left.size() && heights[left.top()] >= heights[i]) left.pop();
            l[i] = left.size() ? left.top() : -1; // 注意如果栈中空了，说明h[i]比左边所有柱子都高，直接向左取到-1
            left.push(i);
        }
        // 从右往左维护一个单调（如果出现了新的更小的柱子，之前的就不需要了）
        for (int i = n - 1; i >= 0; i--) {
            while (right.size() && heights[right.top()] >= heights[i]) right.pop();
            r[i] = right.size() ? right.top() : n; // 直接向右取到n
            right.push(i);
        }

        for (int i = 0; i < n; i++) {
            res = max(res, heights[i] * (r[i] - l[i] - 1)); // 注意宽度是是r - l - 1
        }

        return res;
    }
};