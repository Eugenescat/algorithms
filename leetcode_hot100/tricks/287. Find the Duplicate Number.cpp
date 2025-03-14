class Solution {
public:
    // 转换成双指针算法 142题
    // 用下标n和nums[n]建立映射关系
    // 判断方式1: 因为nums[n]的范围在[1,n], 而下标范围是[0, n], 所以nums[nums[n]]永远不会超出下标范围，显然会进入无限循环
    // 判断方式2: n+1个下标代表有n+1条边（映射关系），数字[1,n]范围内代表有n个节点，通过图的基本性质可知，一定存在一个环
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