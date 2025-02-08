#include <unordered_map>
using namespace std;

class Solution {
public:
  int getDistinctPairs(vector<int>& stocksProfit, int target) {
    unordered_map<int, int> freq;
    
    int count = 0;

    for (int profit: stocksProfit) {
      int complement = target - profit;
      if (freq[complement] > 0) {
        count ++;
        freq[complement] = 0; // Note that because there are two instances of 3 in stocksProfit there are two pairs matching (9, 3): 
      }
      freq[profit] ++;
    }

    return count;
  }
};