class Solution {
public:
    // 贪心
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;

        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];

        for (int i = 0; i < intervals.size(); i++)
        {
            if (r < intervals[i][0]) {
                res.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else if (r > intervals[i][1]) continue;
            else r = intervals[i][1];
        }
        res.push_back({l, r}); // 记得保存最后一个区间

        return res;
    }
};