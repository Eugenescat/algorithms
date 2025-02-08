#include<unordered_map>

class Solution {
public:
  const int MOD = 10^9 + 7;
  int getStablePeriodsCount(vector<int> revenues, int k) {
    if (k == 0) return 0;
    
    unordered_map<int, int> freq; // space: O(n)
    int n = revenues.size(), distinctVal = 0;
    int count = 0;
    int left = 0, right = 0;

    for (; right < n; right ++) {
      if (++freq[revenues[right]] == 1) distinctVal ++;
      
      while (distinctVal > k) {
        if(--freq[revenues[left]] == 0) distinctVal --;
        left ++;
      }

      count += right - left + 1;
      count %= MOD;
    }

    return count;
  }
};