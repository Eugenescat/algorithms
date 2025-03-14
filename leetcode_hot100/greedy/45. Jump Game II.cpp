class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int end = 0; // 某一步的范围
        // 注意这里只遍历到size-2，因为题目已经说确定可以到达size-1，这样可以避免进入到size-1时又开启新一步
        for (int i = 0, j = 0; i < nums.size() - 1; i++) {
            j = max(j, i + nums[i]); // 当前步中所有点能到的最大范围
            if (i == end) { // 如果i到达了这一步的范围边界
                end = j;
                step++;// 开始新一步
            }
        }
        return step;
    }
};