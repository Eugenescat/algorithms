class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 用两个单调栈求每个数左边和右边第一个比它小的数
        int n = heights.size();
        stack<int> left, right;
        vector<int> l(n), r(n);
        int res = 0;
        for (int i = 0; i < n; i ++) {
            while (left.size() && heights[left.top()] >= heights[i]) left.pop();
            l[i] = left.size()? left.top() : -1; // 注意如果栈中空了，说明h[i]比左边所有柱子都高，直接取到-1
            left.push(i);
        }
        for (int i = n - 1; i >= 0; i --) {
            while (right.size() && heights[right.top()] >= heights[i]) right.pop();
            r[i] = right.size()? right.top() : n; // 栈空直接取到n
            right.push(i);
        }
        for (int i = 0; i < n; i ++) {
            res = max(res, (r[i] - l[i] - 1) * heights[i]); // 注意宽度是是r - l - 1
        }
        return res;
    }
};