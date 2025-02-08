
class Solution {
public:
  vector<string> checkSimilarPasswords(vector<string> newPasswords, vector<string> oldPasswords) {
    vector<string> res;
    int n = newPasswords.size();

    for (int k = 0; k < n; k++) {
      string& newP = newPasswords[k];
      string& oldP = oldPasswords[k];

      int i = 0, j = 0;
      while(i < newP.size() && j < oldP.size()) {
        if (newP[i] == oldP[j] ||
          ((newP[i] - 'a' + 1) % 26 + 'a' == oldP[j])) j++;
        i++;
      }

      if (j == oldP.size()) res.push_back("YES");
      else res.push_back("NO");
    }

    return res;
  }
};