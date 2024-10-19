class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 时间复杂度从n^3降为n^2(利用单调性)，先确定i，再对j和k从两头向中间双指针
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // 对原数组排序（因为结果不要求还原下标）呈现单调性
        for (int i = 0; i < nums.size(); i ++) // 先确定i
        {
            if (i && nums[i] == nums[i - 1]) continue;  // 跳过重复的i
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) // 再确定j
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // 跳过重复的j
                // 从后一步开始思考
                while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0) k --; // 直到取k-1时最接近0
                if (nums[i] + nums[j] + nums[k] == 0) res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};