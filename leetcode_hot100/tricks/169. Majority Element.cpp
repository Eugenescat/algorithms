class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int r;
        int inv = 0;
        for (int num: nums) {
            if (!inv) r = num, inv = 1;
            else if (num == r) inv ++;
            else inv --;
        }
        return r;
    }
};