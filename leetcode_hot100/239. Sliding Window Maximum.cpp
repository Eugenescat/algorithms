class Solution {
public:
    // 维护一个单调递减的双端队列作为窗口，淘汰掉永远不可能成为最大值的值，这样就不需要遍历窗口k
    // 淘汰策略：i < j且nums[i] < nums[j]，则i永远不可能是窗口最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++)
        {
            // 新加进一个元素的时候记得除掉离开窗口的元素
            if (q.size() && i - k + 1 > q.front()) q.pop_front();
            // 维护队列单调性
            while (q.size() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};