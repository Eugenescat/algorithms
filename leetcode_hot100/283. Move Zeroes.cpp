class Solution {
public:
    // 第一个指针永远指向下一个该放东西的位置，第二个指针去找下一个非0的值，找到即交换
    void moveZeroes(vector<int>& nums) {
        int k = 0; // 即第一个指针
        for (auto x: nums)
            if (x) // x不是0
                nums[k++] = x; // nums[k] = x; k++
        while (k < nums.size()) nums[k ++] = 0;
    }
};