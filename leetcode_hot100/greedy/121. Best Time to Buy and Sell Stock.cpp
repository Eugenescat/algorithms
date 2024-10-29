class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int m = INT_MAX;
        for (auto p : prices) {
            m = min(m, p);
            res = max(res, p - m);
        }
        return res;
    }
};