class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 用j记录已经遍历过的i最远能到达的位置
        for (int i = 0, j = 0; i < nums.size(); i ++) {
            if (j < i) return false;
            j = max(j, i + nums[i]);
        }
        return true;
    }
};