class Solution {
public:
    // 模版题：快速选择算法
    int quick_sort(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[k];
        int x = nums[l + r >> 1], i = l - 1, j = r + 1;
        while (i < j) {
            do i ++; while (nums[i] > x); // 注意这里跟模版的符号反转了一下，因为这道题需要从大到小排序
            do j --; while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (k <= j) return quick_sort(nums, l, j, k);
        else return quick_sort(nums, j + 1, r, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, k - 1); // 找第 k 大的元素，实际上需要找数组中第 k-1 个索引的元素
    }
};