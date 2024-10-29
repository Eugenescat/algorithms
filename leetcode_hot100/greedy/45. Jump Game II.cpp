class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int idx = 0; // 某一步的范围
        int m = 0; // 范围内所有点能走的最远长度
        for (int i = 0; i < nums.size() - 1; i ++) {
            m = max(m, i + nums[i]);
            if (i == idx) {
                idx = m;
                step ++;
            }
        }
        return step;
    }
};