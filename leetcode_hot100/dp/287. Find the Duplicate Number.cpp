class Solution {
public:
    // 转换成双指针算法 142题
    // 用下标n和nums[n]建立映射关系，该图中必然有环
    int findDuplicate(vector<int>& nums) {
        int s = 0, f = 0;
        while (true) {
            s = nums[s];
            f = nums[nums[f]];
            // 快慢指针相遇
            if (s == f) {
                // 让慢指针从0开始走
                s = 0;
                while (s != f) {
                    s = nums[s];
                    f = nums[f];
                }
                return s;
            }
        }

    }
};