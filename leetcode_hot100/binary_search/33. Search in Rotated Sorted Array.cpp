class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        // 如果不存在两段线
        if (!nums.size()) return -1;
        if (nums[l] <= nums[r]) {
            for (int i = 0; i < nums.size(); i ++) {
                if (nums[i] == target) return i;
            }
            return -1;
        }

        // 找到第一个小于nums[0]的点
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0]) r = mid; // 如果mid小于nums[0]，target在mid或者mid左侧
            else l = mid + 1;
        }
        
        // 在第一个区间内
        if (target >= nums[0]) l = 0, r = r - 1;
        // 在第二个区间
        else l = r, r = nums.size() - 1;
        // 执行二分
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[r] == target) return r;
        else return -1;
    }
};