class Solution {
public:
    // 思路：第一遍遍历把每个正整数（x+1)放到对应下标(x)的位置上，第二遍遍历遇到的第一个和坐标+1不相等的数就是答案
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while ((nums[i] > 0 && nums[i] <= n) && nums[i] != (i+1) && nums[i] != nums[nums[i] - 1]) 
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1) return i + 1;
        return n + 1;
    }
};