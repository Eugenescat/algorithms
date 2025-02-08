class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k;) {
            if (nums[i] == 0) swap(nums[i++], nums[j++]); // 为什么这里不处理交换过来的数：因为从j~i都是1，所以交换过来的这个值就是1，不用再检查
            else if (nums[i] == 2) swap(nums[i], nums[k--]);
            else i++;
        }
    }
};