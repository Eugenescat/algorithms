class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // 注意有可能旋转到刚好是原来的数组
        if (nums[l] <= nums[r]) return nums[l];
        // 找到最靠左侧的一个小于nums[0]的数
        while (l < r) {
            int mid  = l + r >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};