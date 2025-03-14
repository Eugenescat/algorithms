class Solution {
public:
    // 如果整个数组是降序的，则已经是最大的排列（因为尽可能把最大的数组摆在最高位上）
    void nextPermutation(vector<int>& nums) {
        // 找到非单调递减前的位置
        int k = nums.size() - 1;
        while (k && nums[k-1] >= nums[k]) k--; // k 是单调递减段的最后一个位置
        // 如果本身就单调递减，回到第一个位置
        if (k <= 0) reverse(nums.begin(), nums.end());
        else {
            // 否则，返回去找到应该交换过来的坐标(最小的大于n的数)
            int idx = k;
            while (idx+1 < nums.size() && nums[idx+1] > nums[k-1]) idx ++;
            swap(nums[idx], nums[k-1]);
            // 把后续几位重置成单调递增
            reverse(nums.begin() + k, nums.end());
        }
    }
};