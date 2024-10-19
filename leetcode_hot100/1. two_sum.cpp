class Solution {
public:
    // 思路：使用哈希表存储已经遍历过的元素，每次遍历到一个元素，就查找哈希表中是否有满足条件的元素
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        // 每次都只找自己之前的
        for (int i = 0; i < nums.size(); i ++)
        {
            int r = target - nums[i];
            if (map.count(r)) return {map[r], i};
            map[nums[i]] = i;
        }

        return {};
    }
};