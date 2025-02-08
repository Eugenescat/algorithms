
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    int left = intervals[0][0], right = intervals[0][1];

    for (vector<int> interval : intervals) {
      if (interval[0] > right) {
        res.push_back({left, right});
        left = interval[0];
        right = interval[1];
      } else if (interval[1] > right) {
        right = interval[1];
      }
    }

    res.push_back({left, right});
    return res;
  }
};