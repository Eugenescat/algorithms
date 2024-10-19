class Solution {
public:
    // 用动态规划做0(n)（还有一种分治做法，但更拉，懒得做）
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for (int i = 0, last = 0; i < nums.size(); i++)
        {
            last = max(0, last) + nums[i];
            res = max(res, last);
        }
        return res;
    }
};