
class Solution {
public:
  int groupStudents(vector<int>& levels, int maxSpread) {
    if (levels.empty()) return 0;

    sort(levels.begin(), levels.end()); // step1: nlogn
    int i = 0, n = levels.size();
    int count = 1;
    int start = levels[0];
    // step2: O(n)
    for (int level: levels) {
      if (level - start > maxSpread) {
        count ++;
        start = level;
      }
    }

    return count;
  }
};