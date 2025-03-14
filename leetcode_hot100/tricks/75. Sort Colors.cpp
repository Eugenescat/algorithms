class Solution {
public:
    // 这不是双指针吗？
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k;) { // 必须是i <= k，否则最后一个nums[k]漏检查
            if (nums[i] == 0) swap(nums[i++], nums[j++]); // j原本指向的数只可能是0或1(如果是2的话早就被i指针换走到末尾了),所以i可以++跳过
            else if (nums[i] == 2) swap(nums[i], nums[k--]); // k原本指向的数什么都有可能，所以还需要继续用i指针检查,i不能++
            else i++;
        }
    }
};