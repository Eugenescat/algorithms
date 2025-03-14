class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ele = 0;
        for (int num: nums) ele ^= num;
        return ele;
    }
};